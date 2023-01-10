/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:08:24 by mkhairal          #+#    #+#             */
/*   Updated: 2022/11/02 18:09:59 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handle_d_i(int d)
{
	int		size;
	char	*str;
	int		len;

	len = 0;
	size = get_nbr_length(d);
	str = ft_itoa(d);
	len += ft_putstr(str);
	free(str);
	return (len);
}

int	ft_handle_x(unsigned long nb, int cap)
{
	int	len;

	len = 0;
	if (!cap)
		len += ft_print_address(nb, 0);
	else
		len += ft_print_address(nb, 1);
	return (len);
}

int	ft_handle_p(unsigned long long nb)
{
	int	len;

	len = 0;
	len += ft_putstr(PRE);
	len += ft_print_hex(nb);
	return (len);
}

int	ft_handle_u(unsigned long nb)
{
	int	len;

	len = 0;
	len += ft_putnbr(nb);
	return (len);
}

void	ft_handle(char *s, va_list *lst, int *len)
{
	int	i;

	i = 0;
	if (s[i] == 'd' || s[i] == 'i')
		*len += ft_handle_d_i(va_arg(*lst, int));
	else if (s[i] == 'x')
		*len += ft_handle_x(va_arg(*lst, unsigned long), 0);
	else if (s[i] == 'p')
		*len += ft_handle_p(va_arg(*lst, unsigned long long));
	else if (s[i] == 'X')
		*len += ft_handle_x(va_arg(*lst, unsigned long), 1);
	else if (s[i] == 'u')
		*len += ft_handle_u(va_arg(*lst, unsigned long));
	else if (s[i] == 'c')
		*len += ft_handle_c(va_arg(*lst, char *));
	else if (s[i] == 's')
		*len += ft_handle_s(va_arg(*lst, char *));
	else if (s[i] == '%')
		*len += ft_putchar('%');
}
