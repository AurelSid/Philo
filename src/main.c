/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:41:20 by asideris          #+#    #+#             */
/*   Updated: 2024/08/15 13:11:01 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}
int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->death_count_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->starting_block, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->finished_p_mutex, NULL) != 0)
		return (0);
	while (i < data->philo_c)
	{
		if (pthread_mutex_init(&data->philo_array[i].own_fork, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_get_args(argc, argv, &data))
		return (0);
	data.start_time = get_current_time_in_ms();
	data.philo_array = ft_calloc(data.philo_c, sizeof(t_philosopher));
	data.finished_philos = 0;
	ft_init_mutex(&data);
	ft_init_threads(&data);
	pthread_create(&data.monitor, NULL, monitor, &data);
	pthread_join(data.monitor, NULL);
	return (0);
}
