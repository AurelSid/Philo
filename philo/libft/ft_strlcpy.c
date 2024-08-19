/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:30:54 by asideris          #+#    #+#             */
/*   Updated: 2024/04/17 14:33:16 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (src[j])
	{
		j++;
	}
	if (dstsize == 0)
		return (j);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
/*#include<stdio.h>
#include <string.h>

int	main(void)
{
  char dest[10];
  char src[] = "hello";
  size_t test;
  test = ft_strlcpy(dest,src,3);
  printf("%zu\n",ft_strlcpy(dest, src, 3));
  printf("%zu\n",test);
  test = strlcpy(dest,src,3);
  printf("%zu\n",test);
}*/
