/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:18:03 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/23 15:33:42 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	char	*str;
	char	*t;

	str = malloc(sizeof(char) * len + 1);
	t = str;
	if (!s)
		return (NULL);
	if (!str)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		*str = '\0';
		return (t);
	}
	while (len && (s + start))
	{
		*str = *(s + start);
		str++;
		start++;
		len--;
	}
	*str = '\0';
	return (t);
}
