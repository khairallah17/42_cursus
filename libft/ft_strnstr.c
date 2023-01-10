/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:27:25 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/30 18:26:19 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static char	*cmp(char *s1, char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		counter;

	i = 0;
	counter = 0;
	while (s1[i] && n)
	{
		j = 0;
		counter = 0;
		while (s2[j] && j < n)
		{
			if (s2[j] == s1[i + j])
				counter++;
			j++;
		}
		if (counter == ft_strlen(s2))
			return (s1);
		i++;
		n--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	i = 0;
	if (!*needle || n == 0)
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		if (haystack[i] == needle[0])
			return (cmp(((char *)haystack) + i, (char *)needle, n));
		i++;
	}
	return (NULL);
}
