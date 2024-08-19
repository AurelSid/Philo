/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:43:04 by asideris          #+#    #+#             */
/*   Updated: 2024/04/17 20:57:16 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (s1[0] == '\0')
	{
		return (ft_strdup(""));
	}
	start = 0;
	end = ft_strlen(s1);
	while (ft_isset(s1[start], set) == 1)
	{
		start++;
	}
	while (ft_isset(s1[end - 1], set) == 1)
	{
		end--;
	}
	if (end == start)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start));
}
/*#include<stdio.h>
int	main(void)
{
	printf("%s\n", ft_strtrim("", ""));
}*/
