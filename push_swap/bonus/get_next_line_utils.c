/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:40:17 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 23:23:00 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	int		flag;

	if (!s)
		return (0);
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

