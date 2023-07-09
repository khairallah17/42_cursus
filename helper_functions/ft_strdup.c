/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:01:53 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/09 14:02:07 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
