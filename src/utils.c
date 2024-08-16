/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:41:20 by asideris          #+#    #+#             */
/*   Updated: 2024/08/16 14:16:29 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void lock_own_first()
{}
int	ft_pickup_forks(t_philosopher *philo)
{
	if (pthread_mutex_lock(&philo->own_fork) == 0)
	{
		pthread_mutex_lock(&philo->data->finished_p_mutex);
		pthread_mutex_lock(&philo->data->death_count_mutex);
		if (philo->data->finished_philos < philo->data->philo_c
			&& philo->data->death_count == 0)
		{
			pthread_mutex_lock(&philo->data->print_lock);
			printf("%-15ld %-5d %-15s\n", get_current_time_in_ms()
				- philo->data->start_time, philo->id, "picked up fork");
			pthread_mutex_unlock(&philo->data->print_lock);
		}
		pthread_mutex_unlock(&philo->data->death_count_mutex);
		pthread_mutex_unlock(&philo->data->finished_p_mutex);
	}
	if (pthread_mutex_lock(philo->next_fork) == 0)
	{
		pthread_mutex_lock(&philo->data->finished_p_mutex);
		if (philo->data->finished_philos < philo->data->philo_c
			&& philo->data->death_count == 0)
		{
			pthread_mutex_lock(&philo->data->print_lock);
			printf("%-15ld %-5d %-15s\n", get_current_time_in_ms()
				- philo->data->start_time, philo->id, "picked up fork");
			pthread_mutex_unlock(&philo->data->print_lock);
		}
		pthread_mutex_unlock(&philo->data->finished_p_mutex);
		philo->state = 'e';
		ft_reset_clock(philo);
	}
	return (0);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time_in_ms();
	while ((get_current_time_in_ms() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	print_status(int philosopher_id, t_data *data, const char *status)
{
	long	timestamp;

	timestamp = get_current_time_in_ms() - data->start_time;
	pthread_mutex_lock(&data->death_count_mutex);
	pthread_mutex_lock(&data->finished_p_mutex);
	if (data->finished_philos < data->philo_c && data->death_count == 0)
	{
		pthread_mutex_lock(&data->print_lock);
		printf("%-15ld %-5d %-15s\n", timestamp, philosopher_id, status);
		pthread_mutex_unlock(&data->print_lock);
	}
	pthread_mutex_unlock(&data->death_count_mutex);
	pthread_mutex_unlock(&data->finished_p_mutex);
}
