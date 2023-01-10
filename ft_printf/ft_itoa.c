/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:06:39 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/29 22:56:34 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
