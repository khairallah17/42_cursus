/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:58:29 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 00:53:05 by mkhairal         ###   ########.fr       */
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

int	*convert_to_int(char **str, int size)
{
	int	i;
	int	*tab;

	i = -1;
	tab = (int *)malloc(sizeof (int) * size);
			printf("conv to int %p\n", tab);
	if (!tab)
		return (0);
	while (++i < size)
		tab[i] = ft_atoi(str[i]);
	i = -1;
	check_duplicates(tab, size);
	return (tab);
}

int	check_splitable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i] == ' ')
			return (0);
	return (1);
}
