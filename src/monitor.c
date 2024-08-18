/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:51:13 by asideris          #+#    #+#             */
/*   Updated: 2024/08/18 14:29:53 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_found_dead(t_data *data)
{
	long	current_time;

	current_time = get_current_time_in_ms() - data->start_time;
	pthread_mutex_lock(&data->print_lock);
	printf("%d is deads\n", data->death_count);
	pthread_mutex_unlock(&data->print_lock);
}

int	check_finished_philosophers(t_data *data)
{
	int	finished_philos;

	pthread_mutex_lock(&data->finished_p_mutex);
	finished_philos = data->finished_philos;
	pthread_mutex_unlock(&data->finished_p_mutex);
	if (finished_philos >= data->philo_c)
	{
		data->break_threads = 1;
		pthread_mutex_lock(&data->print_lock);
		pthread_mutex_unlock(&data->print_lock);
		exit_clean(data, data->philo_c, 1);
		return (1);
	}
	return (0);
}

int	check_philosopher_death(t_data *data, int i)
{
	long	current_time;
	long	elapsed_time;

	current_time = get_current_time_in_ms();
	pthread_mutex_lock(&data->philo_array[i].lock_tslm);
	elapsed_time = current_time - data->philo_array[i].time_of_last_meal;
	pthread_mutex_unlock(&data->philo_array[i].lock_tslm);
	if (elapsed_time > data->t_to_die)
	{
		data->break_threads = 1;
		data->philo_array[i].time_waited = elapsed_time;
		pthread_mutex_lock(&data->death_count_mutex);
		data->death_count = i + 1;
		pthread_mutex_unlock(&data->death_count_mutex);
		ft_found_dead(data);
		exit_clean(data, data->philo_c, 3);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;
	int		finished;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_c)
		{
			if (check_finished_philosophers(data)
				|| check_philosopher_death(data, i))
				break ;
			i++;
		}
		pthread_mutex_lock(&data->finished_p_mutex);
		finished = data->finished_philos;
		pthread_mutex_unlock(&data->finished_p_mutex);
		if (finished >= data->philo_c || data->death_count > 0)
			break ;
	}
	return (NULL);
}

int	ft_reset_clock(t_philosopher *philo)
{
	long	current_time;

	current_time = get_current_time_in_ms();
	pthread_mutex_lock(&philo->lock_tslm);
	philo->time_of_last_meal = current_time;
	pthread_mutex_unlock(&philo->lock_tslm);
	return (1);
}
