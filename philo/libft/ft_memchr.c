/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:44:37 by asideris          #+#    #+#             */
/*   Updated: 2024/04/19 17:51:10 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	printf("%s" "%c", ft_memchr("HELLO", 'P', 50), '\n');
	printf("%s", memchr("HELLO", 'P', 50));
}*/
