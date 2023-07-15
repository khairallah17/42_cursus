/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:32:17 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 22:56:54 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_atoi(const char *nptr)
{
	int			signe_counter;
	long		result;
	int			i;

	result = 0;
	i = 0;
	signe_counter = 1;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32) && nptr[i])
		i++;
	if (nptr[i] == '-')
	{
		signe_counter = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
		quite_exit();
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	result *= signe_counter;
	if (result > INT_MAX || result < INT_MIN)
		quite_exit();
	return (result);
}
