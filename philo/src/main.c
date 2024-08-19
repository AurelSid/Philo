/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:41:20 by asideris          #+#    #+#             */
/*   Updated: 2024/08/19 17:03:50 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_init_data_mutexes(t_data *data)
{
	data->philo_array = ft_calloc(data->philo_c, sizeof(t_philosopher));
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->lock_break, NULL) != 0)
		return (ft_destroy_mutexes(1, data));
	if (pthread_mutex_init(&data->death_count_mutex, NULL) != 0)
		return (ft_destroy_mutexes(2, data));
	if (pthread_mutex_init(&data->starting_block, NULL) != 0)
		return (ft_destroy_mutexes(3, data));
	if (pthread_mutex_init(&data->finished_p_mutex, NULL) != 0)
		return (ft_destroy_mutexes(4, data));
	return (0);
}

int	ft_init_philo_mutexes(t_philosopher *philo)
{
	if (pthread_mutex_init(&philo->own_fork, NULL))
	{
		ft_destroy_forks(3, philo->data);
		return (0);
	}
	if (pthread_mutex_init(&philo->lock_tslm, NULL))
	{
		pthread_mutex_destroy(&philo->own_fork);
		ft_destroy_forks(3, philo->data);
		return (0);
	}
	if (pthread_mutex_init(&philo->lock_eat_c, NULL))
	{
		pthread_mutex_destroy(&philo->own_fork);
		pthread_mutex_destroy(&philo->lock_tslm);
		ft_destroy_forks(3, philo->data);
		return (0);
	}
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	ft_init_data_mutexes(data);
	while (i < data->philo_c)
	{
		ft_init_philo_mutexes(&data->philo_array[i]);
		i++;
	}
	return (1);
}

void	ft_fill_data(t_data *data)
{
	data->mutex_array[0] = data->print_lock;
	data->mutex_array[1] = data->death_count_mutex;
	data->mutex_array[2] = data->starting_block;
	data->mutex_array[3] = data->finished_p_mutex;
	data->break_threads = 0;
	data->finished_philos = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_get_args(argc, argv, &data))
	{
		printf("Please check arguments range and validity\n");
		return (0);
	}
	if (!ft_init_mutex(&data))
	{
		free(data.philo_array);
		return (0);
	}
	ft_fill_data(&data);
	ft_init_threads(&data);
	pthread_create(&data.monitor, NULL, monitor, &data);
	pthread_join(data.monitor, NULL);
	system("leaks philosophers");
	return (0);
}
