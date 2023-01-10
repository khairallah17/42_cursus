/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:06:19 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/29 23:00:01 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_hex(unsigned long long number)
{
	int	base;
	int	len;

	len = 0;
	base = 16;
	if (number < base)
		len += ft_putchar(HEXADECIMAL[number]);
	else
	{
		ft_print_hex(number / base);
		len += ft_putchar(HEXADECIMAL[number % base]);
	}
	return (len);
}
