/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:22:45 by asideris          #+#    #+#             */
/*   Updated: 2024/04/17 14:33:19 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
/*#include<string.h>
#include <stdio.h>

int	main(void)
{
	unsigned int nb = 4;
	char string1[] = "hllio";
	char string2[] = "hlzo";

	printf("%d\n",ft_strncmp(string1, string2, nb));
	printf("%d\n",strncmp(string1, string2, nb));
}*/