/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:24:11 by Asideris          #+#    #+#             */
/*   Updated: 2024/04/17 14:32:42 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}
/*#include<stdio.h>
int	main(int argc, char **argv)
{
	printf("argc:%d result:%d \n",argc,ft_isalnum(argv[1][0]));
}*/
