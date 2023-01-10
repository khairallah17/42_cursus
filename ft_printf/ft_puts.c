/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:05:51 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/29 22:59:14 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i])
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}

int	ft_putnbr(unsigned long n)
{
	unsigned int	number;
	int				len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		number = -n;
	}
	else
			number = n;
	if (number > 9)
	{
		ft_putnbr(number / 10);
		number %= 10;
	}
	len += ft_putchar(number + '0');
	return (len);
}
