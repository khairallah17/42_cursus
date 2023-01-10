/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:05:31 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/23 15:33:07 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	int		flag;

	flag = 0;
	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + i));
	while (*s)
	{
		if ((char)*s == (char)c)
		{
			flag = 1;
			break ;
		}
		s++;
	}
	if (!flag)
		return (NULL);
	return ((char *)s);
}
