/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:34:00 by asideris          #+#    #+#             */
/*   Updated: 2024/04/17 20:56:41 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;

	dest_len = ft_strlen(dst);
	if (dstsize <= dest_len)
		return (dstsize + ft_strlen(src));
	ft_strlcpy(dst + dest_len, src, dstsize - dest_len);
	return (dest_len + ft_strlen(src));
}

/*#include <string.h>
int	main(void)
{
	const char src[] = "Hello";
	char dest[10] = "sir";
	char dest2[10] = "sir";
	printf("%zu\n",ft_strlcat(dest, src, 10));
	printf("%s\n",dest);
	printf("%zu\n",(size_t)strlcat(dest2, src, 10));
	printf("%s\n",dest2);


}*/