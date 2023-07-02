/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:25:54 by mkhairal          #+#    #+#             */
/*   Updated: 2023/06/21 15:08:34 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_first_line(int fd, char *str)
{
	char	*file;
	int		read_byte;

	file = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_byte = 1;
	if (!file)
		return (0);
	while (!ft_strchr(str, '\n') && read_byte)
	{
		read_byte = read(fd, file, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(file);
			return (0);
		}
		file[read_byte] = '\0';
		str = ft_strjoins(str, file);
	}
	free(file);
	return (str);
}

char	*read_correct_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*read_next_line(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	line = (char *)malloc(ft_strlen(str) - i + 1);
	if (!line)
		return (0);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*file;
	static char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_first_line(fd, str);
	if (!str)
	{
		free(str);
		return (0);
	}
	file = read_correct_line(str);
	str = read_next_line(str);
	return (file);
}
