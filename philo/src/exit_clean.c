/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:53:33 by asideris          #+#    #+#             */
/*   Updated: 2024/08/19 17:03:18 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	exit_clean(t_data *data, int index, int flag)
{
	int	i;

	i = 0;
	while (i < index)
	{
		pthread_join(data->philo_array[i].this_thread, NULL);
		i++;
	}
	if (flag == 1)
		printf("");
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
	int	i;

	i = 0;
	while (i < fork_index)
	{
		pthread_mutex_destroy(&data->philo_array[i].own_fork);
		i++;
	}
	return (0);
}
