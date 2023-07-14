/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:01:53 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 00:55:03 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*t;

	s = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
			printf("strdup %p\n", s);
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
strdup 0x7fb1aec05850
join 0x7fb1aec05850
join 0x7fb1aec05860
join 0x7fb1aec05860
join 0x7fb1aec05860
join 0x7fb1aec05860
join 0x7fb1aec05860
join 0x7fb1aec05860
join 0x7fb1aec05860
join 0x7fb1aec05860
split 0x7fb1aec05880
check_set 0x7fb1aec05850
check_set 0x7fb1aec058c0
check_set 0x7fb1aec058d0
check_set 0x7fb1aec058e0
check_set 0x7fb1aec058f0
check_set 0x7fb1aec05900
conv to int 0x7fb1aec05860
create  0x7fb1aec05910
create  0x7fb1aec05930
create  0x7fb1aec05950
create  0x7fb1aec05970
create  0x7fb1aec05990
create  0x7fb1aec059b0