/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:45:18 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/23 16:39:31 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*t;

	s = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	t = s;
	if (!s1)
	{
		free(s);
		return (NULL);
	}
	if (!s)
		return (NULL);
	while (*s1)
	{
		*s = *s1;
		s++;
		s1++;
	}
	*s = '\0';
	return (t);
}
