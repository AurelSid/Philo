/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:24:26 by marvin            #+#    #+#             */
/*   Updated: 2024/04/17 20:56:31 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_free(int i, char **array)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static int	ft_tokencount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static int	ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

char	**split(char const *s, char c, char **array, int wordcount)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < wordcount)
	{
		while (s[j] && s[j] == c)
		{
			j++;
		}
		array[i] = ft_substr(s, j, ft_wordlen(&s[j], c));
		if (!array[i])
		{
			ft_free(i, array);
			return (NULL);
		}
		while (s[j] && s[j] != c)
		{
			j++;
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		wordcount;

	wordcount = ft_tokencount(s, c);
	array = malloc(sizeof(char *) * (wordcount + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, wordcount);
	return (array);
}
/*int	main(void)
{
	char	c;
	char	*str;
	int		i;
	char **array;

	i = 0;
	c = ' ';
	str = "   h   ello    ";
	array = ft_split(str, c);

	while(array[i])
	{
		printf("%s \n", array[i]);
		i++;
	}



}*/
