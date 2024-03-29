/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:57:56 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 22:58:04 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_signe(char c)
{
	return (c == '-' || c == '+');
}

int	check_invalid_chars(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!is_number(str[i][j]) && !is_signe(str[i][j]))
				quite_exit();
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicates(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				quite_exit();
			j++;
		}
		i++;
	}
	return (0);
}

int	check_for_max_int(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]))
				quite_exit();
		}
		i++;
	}
	return (0);
}
