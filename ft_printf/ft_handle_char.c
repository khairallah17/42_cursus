/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:08:32 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/29 23:00:33 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handle_c(char *d)
{
	int len;

	len = 0;
	len += ft_putchar(d);
	return (len);
}

int	ft_handle_s(char *t)
{
	int	len;

	len = 0;
	if (t == NULL)
	{
		ft_putstr("(null)");
		return (len);
	}
	len = ft_putstr(t);
	return (len);
}
