/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:40:17 by mkhairal          #+#    #+#             */
/*   Updated: 2022/11/18 10:45:10 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strdup(char *s1)
{
	char	*s;
	int		i;

	i = 0;
	if (!s1 || !s1[i])
		return (NULL);
	s = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	int		i;
	int		j;
	char	*s;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	s[j] = '\0';
	free(s1);
	return (s);
}
