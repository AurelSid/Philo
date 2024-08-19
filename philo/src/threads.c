/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:21:36 by asideris          #+#    #+#             */
/*   Updated: 2024/08/18 14:49:51 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_pickup_own_first(t_philosopher *philo)
{
	int	finished_philosophers;
	int	death_count;

	pthread_mutex_lock(&philo->data->death_count_mutex);
	death_count = philo->data->death_count;
	pthread_mutex_unlock(&philo->data->death_count_mutex);
	pthread_mutex_lock(&philo->data->finished_p_mutex);
	finished_philosophers = philo->data->finished_philos;
	pthread_mutex_unlock(&philo->data->finished_p_mutex);
	if (finished_philosophers < philo->data->philo_c && death_count == 0)
	{
		pthread_mutex_lock(&philo->data->print_lock);
		printf("%-15ld %-5d %-15s\n", get_current_time_in_ms()
			- philo->data->start_time, philo->id, "picked up fork");
		pthread_mutex_unlock(&philo->data->print_lock);
	}
	return (0);
}

int	ft_pickup_forks(t_philosopher *philo)
{
	int	finished;
	int	deaths;

	pthread_mutex_lock(&philo->data->finished_p_mutex);
	finished = philo->data->finished_philos;
	pthread_mutex_unlock(&philo->data->finished_p_mutex);
	pthread_mutex_lock(&philo->own_fork);
	ft_pickup_own_first(philo);
	pthread_mutex_lock(philo->next_fork);
	pthread_mutex_lock(&philo->data->death_count_mutex);
	deaths = philo->data->death_count;
	pthread_mutex_unlock(&philo->data->death_count_mutex);
	if (finished < philo->data->philo_c && deaths == 0)
	{
		pthread_mutex_lock(&philo->data->print_lock);
		printf("%-15ld %-5d %-15s\n", get_current_time_in_ms()
			- philo->data->start_time, philo->id, "picked up fork");
		pthread_mutex_unlock(&philo->data->print_lock);
	}
	philo->state = 'e';
	ft_reset_clock(philo);
	return (0);
}

int	ft_set_state(t_philosopher *philo)
{
	if (philo->state == 'e')
	{
		print_status(philo->id, philo->data, "is eating");
		ft_usleep(philo->data->t_to_eat);
		philo->eat_count++;
		if (philo->eat_count == philo->data->min_meals)
		{
			pthread_mutex_lock(&philo->data->finished_p_mutex);
			philo->data->finished_philos++;
			pthread_mutex_unlock(&philo->data->finished_p_mutex);
		}
		pthread_mutex_unlock(philo->next_fork);
		pthread_mutex_unlock(&philo->own_fork);
		philo->state = 's';
		print_status(philo->id, philo->data, "is sleeping");
		ft_usleep(philo->data->t_to_sleep);
		philo->state = 't';
		print_status(philo->id, philo->data, "is thinking");
	}
	return (1);
}

int	check_simulation_end(t_philosopher *philo)
{
	int	finished_philos;
	int	death_count;

	pthread_mutex_lock(&philo->data->finished_p_mutex);
	finished_philos = philo->data->finished_philos;
	pthread_mutex_unlock(&philo->data->finished_p_mutex);
	pthread_mutex_lock(&philo->data->death_count_mutex);
	death_count = philo->data->death_count;
	pthread_mutex_unlock(&philo->data->death_count_mutex);
	if (finished_philos >= philo->data->philo_c || death_count > 0)
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_mutex_lock(&philo->data->starting_block);
	pthread_mutex_unlock(&philo->data->starting_block);
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (check_simulation_end(philo))
			break ;
		ft_pickup_forks(philo);
		ft_set_state(philo);
	}
	return (NULL);
}
