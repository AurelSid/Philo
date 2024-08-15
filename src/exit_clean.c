/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:53:33 by asideris          #+#    #+#             */
/*   Updated: 2024/08/15 12:53:51 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philo.h"

void	wait_for_philosophers(t_data *data, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		pthread_join(data->philo_array[i].this_thread, NULL);
		i++;
	}
}