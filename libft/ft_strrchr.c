/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:28:20 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/23 15:33:35 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		flag;
	char	*t;
	char	*y;

	flag = 0;
	t = (char *)s;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(t));
	while (*t)
	{
		if (*t == (char)c)
		{
			flag = 1;
			y = t;
		}
		t++;
	}
	if (!flag)
		return (NULL);
	return (y);
}
