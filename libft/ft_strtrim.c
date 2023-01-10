/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:09:03 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/30 18:26:55 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*fill(char *start, char *lim, char	*dest)
{
	char	*s;

	s = dest;
	while (start <= lim)
		*(dest++) = *(start++);
	*dest = '\0';
	return (s);
}

static char	*fill_null(void)
{
	char	*res;

	res = (char *)malloc(sizeof(char));
	if (!res)
		return (NULL);
	*res = '\0';
	return (res);
}

static char	*return_result(char	*lim, char *start)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (lim - start + 4));
	if (!res)
		return (NULL);
	res = fill(start - 1, lim + 1, res);
	return (res);
}

char	*ft_strtrim(const char	*s1, const char	*set)
{
	int		i;
	char	*start;
	char	*lim;

	if (!s1)
		return (NULL);
	start = (char *)s1;
	i = ft_strlen(s1) - 1;
	while (*start)
	{
		if (check((char *)set, *(start++)) == 0)
			break ;
		if (i == 0)
			return (fill_null());
		else
			i--;
	}	
	lim = (start + i - 1);
	while (*lim)
	{
		if (check((char *)set, *(lim--)) == 0)
			break ;
		i--;
	}
	return (return_result(lim, start));
}
