/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:18:11 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/30 02:35:14 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*t;
	unsigned char	*s;

	t = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (t == NULL && s == NULL)
		return (dst);
	if (t == s)
		return (dst);
	while (n--)
		*(t++) = *(s++);
	return (dst);
}
