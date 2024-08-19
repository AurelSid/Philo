/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:43:43 by asideris          #+#    #+#             */
/*   Updated: 2024/04/17 14:32:52 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long unsigned int	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
int	main(void)
{
	char src[] = "bbbbb";
	char dest[] = "AAAA";
	printf("%s \n", dest);
	ft_memcpy(dest, src, 2);
	printf("%s \n", dest);
}*/