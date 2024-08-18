/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:21:36 by asideris          #+#    #+#             */
/*   Updated: 2024/08/18 12:17:08 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
