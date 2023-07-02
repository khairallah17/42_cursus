/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:58:29 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/02 16:44:51 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	how_many_numbers(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*convert_to_int(char **str)
{
	int	i;
	int	*tab;
	int	size;

	i = -1;
	size = how_many_numbers(str);
	tab = (int *)malloc(sizeof (int) * size);
	if (!tab)
		return (0);
	while (++i < size)
		tab[i] = ft_atoi(str[i]);
	return (tab);
}
