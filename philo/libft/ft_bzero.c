/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:57:48 by asideris          #+#    #+#             */
/*   Updated: 2024/04/17 14:32:40 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	long unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = 0;
		i++;
	}
}
/*#include<stdio.h>
#include <strings.h>

int	main(void)
{
	char s[] = "hello";
	char s1[] = "hello";
	printf("sttring:%s \n",s);
	ft_bzero(s,3);
	printf("ma fonction :%s \n",s);
	bzero(s1,3);
	printf("fontion officiel : %s \n",s1);
}*/