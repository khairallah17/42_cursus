/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:32:17 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/02 09:33:06 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		signe_counter;
	int		result;

	result = 0;
	signe_counter = 1;
	while (((*nptr >= 9 && *nptr <= 13) || *nptr == 32) && *nptr)
		nptr++;
	if (*nptr == '-')
	{
		signe_counter = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*(nptr++) - '0');
		if (result <= -469762049 && signe_counter == 1)
			return (-1);
		else if (result == INT_MIN)
			break ;
		else if (result <= -469762049 && signe_counter == -1)
			return (0);
	}
	return (result * signe_counter);
}
