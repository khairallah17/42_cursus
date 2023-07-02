/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:16:34 by mkhairal          #+#    #+#             */
/*   Updated: 2023/06/26 17:37:51 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*t;

	s = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	t = s;
	if (!s1)
	{
		free(s);
		return (NULL);
	}
	if (!s)
		return (NULL);
	while (*s1)
	{
		*s = *s1;
		s++;
		s1++;
	}
	*s = '\0';
	return (t);
}

int	ft_strlen(const char *t)
{
	int	i;

	i = 0;
	if (!*t)
		return (0);
	while (t[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(const char	*s1, const char	*s2)
{
	char	*s;
	char	*c;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s)
		return (NULL);
	c = s;
	while (*s1)
	{
		*(s++) = *(s1++);
	}
	while (*s2)
	{
		*(s++) = *(s2++);
	}
	*s = '\0';
	return (c);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	unsigned int	number;
	char			res;

	if (n < 0)
	{
		write(1, "-", 1);
		number = -n;
	}
	else
		number = n;
	if (number > 9)
	{
		ft_putnbr(number / 10);
		number %= 10;
	}
	res = number + '0';
	write(1, &res, 1);
}
