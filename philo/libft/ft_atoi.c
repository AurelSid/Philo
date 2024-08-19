/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:19:30 by asideris          #+#    #+#             */
/*   Updated: 2024/04/18 17:05:50 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_skipwhite(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f')
	{
		i++;
	}
	return (i);
}

int	numbereturn(const char *str, int i, int signe)
{
	long long	result;
	long		buf;

	buf = 0;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if (buf > result && signe == 1)
			return (-1);
		else if (buf > result && signe == -1)
			return (0);
		buf = result;
	}
	return ((int)result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	symbol;

	symbol = 1;
	i = ft_skipwhite(str);
	if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
		return (0);
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		i++;
		symbol = -1;
		return (numbereturn(str, i, symbol) * -1);
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
	{
		i++;
		return (numbereturn(str, i, symbol));
	}
	if (ft_isdigit(str[i]))
		return (numbereturn(str, i, symbol));
	return (0);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char str[] = "
		-2147483645452147483647455456454521474836474554564545";
	printf("ft : %d \n",ft_atoi(str));
	printf("original:%d \n",atoi(str));
}*/