/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_threads.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:01:47 by asideris          #+#    #+#             */
/*   Updated: 2024/08/18 12:03:21 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_philo_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_c)
	{
		data->philo_array[i].eat_count = 0;
		data->philo_array[i].sleep_count = 0;
		data->philo_array[i].state = 't';
		data->philo_array[i].data = data;
		data->philo_array[i].id = i + 1;
		i++;
	}
}

void	ft_init_philo_tslm(t_data *data, int philo_count)
{
	int	i;

	i = 0;
	data->start_time = get_current_time_in_ms();
	while (i < philo_count)
	{
		data->philo_array[i].time_of_last_meal = data->start_time;
		i++;
	}
}

int	ft_init_threads(t_data *data)
{
	int	i;

	i = 0;
	ft_set_philo_data(data);
	pthread_mutex_lock(&data->starting_block);
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
	ft_init_philo_tslm(data, data->philo_c);
	pthread_mutex_unlock(&data->starting_block);
	return (0);
}
