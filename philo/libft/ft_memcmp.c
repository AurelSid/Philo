/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:59:28 by asideris          #+#    #+#             */
/*   Updated: 2024/04/17 14:43:33 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
		{
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		}
		i++;
	}
	return (0);
}

/*#include<stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "hellothere";
	char s2[] = "helloBoy";

	printf("ft_memecmp: %d\n",(ft_memcmp(s1, s2, 7)));
	printf("lib memcmp: %d\n",(memcmp(s1, s2, 7)));
}*/
