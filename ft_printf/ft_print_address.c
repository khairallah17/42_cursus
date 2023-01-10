/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:06:24 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/29 22:59:39 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_address(unsigned int number, int cap)
{
	int	base;
	int	len;

	len = 0;
	base = 16;
	if (cap)
	{
		if (number < base)
			len += ft_putchar(HEX[number]);
		else
		{
			ft_print_address(number / base, cap);
			len += ft_putchar(HEX[number % base]);
		}
	}
	else
	{
		if (number < base)
			len += ft_putchar(HEXADECIMAL[number]);
		else
		{
			ft_print_address(number / base, cap);
			len += ft_putchar(HEXADECIMAL[number % base]);
		}
	}
	return (len);
}
