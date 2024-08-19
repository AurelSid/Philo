/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:03:12 by Asideris          #+#    #+#             */
/*   Updated: 2024/04/17 14:32:47 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d",ft_isprint('a'));
	printf("%d",ft_isprint('	'));
	printf("%d",ft_isprint('3'));
	printf("%d",ft_isprint('}'));
}*/
