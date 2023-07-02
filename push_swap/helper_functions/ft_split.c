/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:33:58 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/02 16:14:40 by mkhairal         ###   ########.fr       */
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
	char	*t;
	char	*str;

	while (*sc)
	{
		if (*sc != c)
		{
			str = (char *)malloc(sizeof(char) * (_size(sc, c) + 1));
			if (!str)
				return (free_all(res));
			t = str;
			while (*sc)
			{
				*(str++) = *(sc++);
				if (*sc == c || *sc == '\0')
					break ;
			}
				*str = '\0';
				*(res++) = t;
		}
		if (*sc == '\0')
			break ;
		sc++;
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
