/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:07:52 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/23 15:32:38 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*s1, const void	*s2, size_t	n)
{
	unsigned char	*t;
	unsigned char	*s;

	s = (unsigned char *)s1;
	t = (unsigned char *)s2;
	if (!n)
		return (0);
	while (n)
	{
		if (*s != *t)
			return (*s - *t);
		s++;
		t++;
		n--;
	}
	return (0);
}
