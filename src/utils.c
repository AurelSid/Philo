/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:41:20 by asideris          #+#    #+#             */
/*   Updated: 2024/08/16 19:35:12 by asideris         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->own_fork);
	ft_pickup_own_first(philo);
	pthread_mutex_lock(philo->next_fork);
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
	return (0);
}

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
	// if (finished_philos < data->philo_c && death_count == 0)
	// {
		pthread_mutex_lock(&data->print_lock);
		printf("%-15ld %-5d %-15s\n", timestamp, philosopher_id, status);
		pthread_mutex_unlock(&data->print_lock);
	// }
}

long	get_current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}
