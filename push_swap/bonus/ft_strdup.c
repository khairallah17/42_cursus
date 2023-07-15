/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:01:53 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 22:57:06 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	s = NULL;
	i = 0;
	if (!s1)
		return (NULL);
	s = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
