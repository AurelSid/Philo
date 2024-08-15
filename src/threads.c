/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:21:36 by asideris          #+#    #+#             */
/*   Updated: 2024/08/15 17:00:10 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_set_state(t_philosopher *philo)
{
	if (philo->state == 'e')
	{
		print_status(philo->id, philo->data, "is eating");
		ft_usleep(philo->data->t_to_eat);
		pthread_mutex_lock(&philo->lock_eat_c);
		philo->eat_count++;
		pthread_mutex_unlock(&philo->lock_eat_c);
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
		pthread_mutex_lock(&philo->data->finished_p_mutex);
		if (philo->data->finished_philos >= philo->data->philo_c
			|| philo->data->death_count > 0)
			break ;
		pthread_mutex_unlock(&philo->data->finished_p_mutex);
		ft_pickup_forks(philo);
		ft_set_state(philo);
	}
	return (NULL);
}

int	ft_init_threads(t_data *data)
{
	int i;

	i = 0;

	while (i < data->philo_c)
	{
		data->philo_array[i].eat_count = 0;
		data->philo_array[i].sleep_count = 0;
		data->philo_array[i].state = 't';
		data->philo_array[i].data = data;
		data->philo_array[i].id = i + 1;
		data->philo_array[i].time_of_last_meal = data->start_time;
		i++;
	}
	i = 0;
	while (i < data->philo_c - 1)
	{
		data->philo_array[i].next_fork = &data->philo_array[i + 1].own_fork;
		i++;
	}
	data->philo_array[i].next_fork = &data->philo_array[0].own_fork;
	i = 0;

	while (i < data->philo_c)
	{
		if (pthread_create(&data->philo_array[i].this_thread, NULL, routine,
				(void *)&data->philo_array[i]) != 0)
		{
			exit_clean(data, i);
			return (1);
		}

		i++;
	}
	pthread_mutex_unlock(&data->starting_block);
	return (0);
}