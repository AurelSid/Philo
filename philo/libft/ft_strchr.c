/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:03:33 by Asideris          #+#    #+#             */
/*   Updated: 2024/04/17 15:40:39 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (0);
}

/*#include<stdio.h>
int	main(void)
{
	const char s[] = "hello";
	int c = 'l';
	printf("%s",ft_strchr(s,c));
	return(0);
}*/