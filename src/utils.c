/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:41:20 by asideris          #+#    #+#             */
/*   Updated: 2024/08/18 14:32:04 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time_in_ms();
	while ((get_current_time_in_ms() - start) < milliseconds)
		usleep(250);
	return (0);
}

void	print_status(int philosopher_id, t_data *data, const char *status)
{
	long	timestamp;
	int		death_count;
	int		finished_philos;

	pthread_mutex_lock(&data->finished_p_mutex);
	finished_philos = data->finished_philos;
	pthread_mutex_unlock(&data->finished_p_mutex);
	pthread_mutex_lock(&data->death_count_mutex);
	death_count = data->death_count;
	pthread_mutex_unlock(&data->death_count_mutex);
	timestamp = get_current_time_in_ms() - data->start_time;
	if (finished_philos < data->philo_c && death_count == 0)
	{
		pthread_mutex_lock(&data->print_lock);
		printf("%-15ld %-5d %-15s\n", timestamp, philosopher_id, status);
		pthread_mutex_unlock(&data->print_lock);
	}
}

long	get_current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
