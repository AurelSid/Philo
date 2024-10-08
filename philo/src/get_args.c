/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:45:07 by asideris          #+#    #+#             */
/*   Updated: 2024/08/19 17:00:18 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_get_args(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		return (0);
	data->philo_c = ft_atoi(argv[1]);
	data->t_to_die = ft_atoi(argv[2]);
	data->t_to_eat = ft_atoi(argv[3]);
	data->t_to_sleep = ft_atoi(argv[4]);
	if (data->philo_c < 1 || data->t_to_die < 1 || data->t_to_eat < 1
		|| data->t_to_sleep < 1)
		return (0);
	if (data->philo_c > 10000 || data->t_to_die > 10000
		|| data->t_to_eat > 10000 || data->t_to_sleep > 10000)
		return (0);
	if (argc == 6)
		data->min_meals = ft_atoi(argv[5]);
	else
		data->min_meals = -1;
	if (argc == 6 && data->min_meals < 1)
	{
		printf("Unvalid meal argument\n");
		return (0);
	}
	return (1);
}