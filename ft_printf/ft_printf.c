/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:06:01 by mkhairal          #+#    #+#             */
/*   Updated: 2022/11/02 11:29:56 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	int		len;
	void	*sc;

	len = 0;
	va_start(lst, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_handle((char *)s, &lst, &len);
		}
		else
			len += ft_putchar(*s);
		s++;
	}
	va_end(lst);
	return (len);
}
