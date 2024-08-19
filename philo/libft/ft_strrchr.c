/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:35:10 by asideris          #+#    #+#             */
/*   Updated: 2024/04/17 14:30:59 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + n));
	while (n >= 0)
	{
		if (((unsigned char *)s)[n] == (unsigned char)c)
		{
			return ((char *)(s + n));
		}
		n--;
	}
	return (NULL);
}
/*#include<stdio.h>
int	main(void)
{
	const char s[] = "ZZZaCCCCaBBaB";
	int c = 'a';
	printf("%s",ft_strrchr(s,c));
	return(0);
}*/