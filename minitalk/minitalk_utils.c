/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:45:28 by mkhairal          #+#    #+#             */
/*   Updated: 2023/05/31 22:19:27 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	check_pid(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	return (0);
}

int	get_nbr_length(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
				n *= -1;
				i++;
	}
	else if (n == 0)
				i++;
	while (n != 0)
	{
				n /= 10;
				i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*number;
	long	nb;

	nb = n;
	size = get_nbr_length(n);
	number = (char *)malloc(size + 1);
	if (!number)
		return (NULL);
	if (nb == 0)
				*number = '0';
	else if (nb < 0)
	{
				nb *= -1;
				*number = '-';
	}
	*(number + size) = '\0';
	while (nb != 0)
	{
				*(number + (size - 1)) = nb % 10 + '0';
				nb /= 10;
				size--;
	}
	return (number);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
