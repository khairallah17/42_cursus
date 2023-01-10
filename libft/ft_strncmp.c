/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:56:43 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/30 18:23:17 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, char const *s2, size_t n)
{
	while (n)
	{
		if (!*s1 || !*s2 || (*s1 != *s2))
			return (((unsigned char)*s1) - ((unsigned char)*s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
