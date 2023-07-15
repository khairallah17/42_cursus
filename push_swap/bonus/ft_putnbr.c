/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:35:35 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 22:56:56 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
