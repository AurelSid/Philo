/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:53:33 by asideris          #+#    #+#             */
/*   Updated: 2024/08/16 15:24:15 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	exit_clean(t_data *data, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		pthread_join(data->philo_array[i].this_thread, NULL);
		i++;
	}
	// ft_destroy_forks(data->philo_c, data);
	// ft_destroy_mutexes(3, data);
	free(data->philo_array);
}

int	ft_destroy_mutexes(int mutex_index, t_data *data)
{
	int	i;

	i = 0;
	while (i < mutex_index)
	{
		pthread_mutex_destroy(&data->mutex_array[i]);
		i++;
	}
	return (0);
}
int	ft_destroy_forks(int fork_index, t_data *data)
{
	int i;
	i = 0;

	while (i < fork_index)
	{
		pthread_mutex_destroy(&data->philo_array[i].own_fork);
		i++;
	}
	return (0);
}