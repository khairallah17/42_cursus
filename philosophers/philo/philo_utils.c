/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:22:20 by mkhairal          #+#    #+#             */
/*   Updated: 2023/08/06 11:07:20 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleepy_head(long sleep)
{
	long long			now;

	now = get_time();
	while ((get_time() - now) < sleep)
		usleep(200);
}

int	ft_atoi(char *nptr)
{
	int		signe_counter;
	int		result;
	int		i;

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
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	return (result * signe_counter);
}
