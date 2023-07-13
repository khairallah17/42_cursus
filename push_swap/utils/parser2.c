/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:19:46 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/13 11:51:03 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_for_numbers(char *str)
{
	int	i;
	int	num;
	int	signe;

	i = 0;
	num = 0;
	signe = 0;
	while (str[i])
	{
		if (is_number(str[i]))
			num++;
		i++;
	}
	return (1);
}
