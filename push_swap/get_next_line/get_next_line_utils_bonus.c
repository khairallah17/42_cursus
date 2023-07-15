/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:35:22 by hasalam           #+#    #+#             */
/*   Updated: 2023/03/25 17:54:27 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str, int flag)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (flag == 0)
	{
		while (str[i])
			i++;
	}
	else
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *str, char *buf)
{
	char	*d;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!buf || !str)
	{
		str = malloc(sizeof(char));
		if (!buf || !str)
			return (NULL);
		str[0] = '\0';
	}
	d = malloc((ft_strlen(str, 0) + ft_strlen(buf, 0)) + 1);
	if (!d)
		return (NULL);
	while (str[++i] != '\0')
		d[i] = str[i];
	while (buf[++j] != '\0')
		d[i + j] = buf[j];
	d[i + j] = '\0';
	free(str);
	return (d);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	if (c == '\0')
	{
		i = ft_strlen(str, 0);
		return ((char *)&str[i]);
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	}
	return (0);
}
