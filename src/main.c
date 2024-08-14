/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:41:20 by asideris          #+#    #+#             */
/*   Updated: 2024/08/14 18:12:37 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int	main(int argc, char **argv)
{
	t_data			data;
	struct timeval	time;

	if (!ft_get_args(argc, argv, &data))
		return (0);
	pthread_mutex_init(&data.print_lock, NULL);
	pthread_mutex_init(&data.death_count_mutex, NULL);
	pthread_mutex_init(&data.starting_block, NULL);
	data.start_time = get_current_time_in_ms();
	data.philo_array = ft_calloc(data.philo_c, sizeof(t_philosopher));
	data.finished_philos = 0;
	gettimeofday(&time, NULL);
	if (ft_init_threads(&data))
	{
		free(data.philo_array);
		return (0);
	}
	pthread_create(&data.monitor, NULL, monitor, &data);
	pthread_join(data.monitor, NULL);
	wait_for_philosophers(&data, data.philo_c);
	return (0);
}
