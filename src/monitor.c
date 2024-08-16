/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:51:13 by asideris          #+#    #+#             */
/*   Updated: 2024/08/16 20:07:43 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_found_dead(t_data *data)
{
	long	current_time;

	// pthread_mutex_lock(&data->death_count_mutex);
	current_time = get_current_time_in_ms() - data->start_time;
	pthread_mutex_lock(&data->print_lock);
	printf("Philo %d died , he waited for %ldms\n", data->death_count,
		data->philo_array[data->death_count - 1].time_waited);
	pthread_mutex_unlock(&data->print_lock);
	// pthread_mutex_unlock(&data->death_count_mutex);
}

void	*monitor(void *arg)
{
	t_data	*data;
	long	elapsed_time;
	long	current_time;
	int		i;
	int		eat_c;
	int		j;

	j = 0;
	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_c)
		{
			pthread_mutex_lock(&data->philo_array[i].lock_eat_c);
			eat_c = data->philo_array[i].eat_count;
			pthread_mutex_unlock(&data->philo_array[i].lock_eat_c);
			if (data->finished_philos >= data->philo_c)
			{
				data->break_threads = 1;
				pthread_mutex_lock(&data->print_lock);
				while (j < data->philo_c)
				{
					printf("filo meals: %d\n", data->philo_array[j].eat_count);
					j++;
				}
				printf("FINISHED------------************************\n");
				pthread_mutex_unlock(&data->print_lock);
				exit_clean(data, data->philo_c);
				break ;
			}
			current_time = get_current_time_in_ms();
			pthread_mutex_lock(&data->philo_array[i].lock_tslm);
			elapsed_time = current_time
				- data->philo_array[i].time_of_last_meal;
			pthread_mutex_unlock(&data->philo_array[i].lock_tslm);
			if (elapsed_time > data->t_to_die)
			{
				data->break_threads = 1;
				data->philo_array[i].time_waited = elapsed_time;
				pthread_mutex_lock(&data->death_count_mutex);
				data->death_count = i + 1;
				pthread_mutex_unlock(&data->death_count_mutex);
				ft_found_dead(data);
				exit_clean(data, data->philo_c);
				break ;
			}
			i++;
		}
		if (data->finished_philos >= data->philo_c || data->death_count > 0)
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
