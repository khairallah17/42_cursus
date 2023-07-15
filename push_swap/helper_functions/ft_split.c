/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:33:58 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/15 21:27:35 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	_size(char *s, char c)
{
	int	size;

	size = 0;
	while (*s)
	{
		if (*(s++) == c)
			break ;
		size++;
	}
	return (size);
}

static void	free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static void	check_set(char *sc, char c, char **res)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (sc[i])
	{
		j = 0;
		if (sc[i] != c)
		{
			str = (char *)malloc(sizeof(char) * (_size(sc + i, c) + 1));
			if (!str)
				return (free_all(res));
			while (sc[i] && sc[i] != c)
				str[j++] = sc[i++];
			str[j] = '\0';
			*(res++) = str;
		}
		if (sc[i] == '\0')
			break ;
		i++;
	}
	*(res) = NULL;
}

static int	size_to_allocate(char *s, char c)
{
	int	size;

	size = 0;
	while (*s)
	{
		if (*s != c)
		{
			size++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (size + 1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	char	*sc;
	char	**y;

	sc = (char *)s;
	if (!sc)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * size_to_allocate(sc, c));
	if (!res)
		return (NULL);
	y = res;
	check_set(sc, c, res);
	return (y);
}
