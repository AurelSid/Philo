/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:41:43 by asideris          #+#    #+#             */
/*   Updated: 2024/04/17 14:41:55 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int nb)
{
	if (nb >= '0' && nb <= '9')
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
int	main(int argc,char **argv)
{
		printf("argc : %d result;%d",argc,(ft_isdigit(argv[1][0])));
}*/
