/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:35:16 by hasalam           #+#    #+#             */
/*   Updated: 2023/03/29 17:52:49 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gline(char *str)
{
	char	*l;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	i = ft_strlen(str, 1);
	if (str[i] != '\n')
		l = malloc(sizeof(char) * i + 1);
	else
		l = malloc(sizeof(char) * i + 2);
	if (!l)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		l[i] = str[i];
	if (str[i] != '\n')
		l[i] = '\0';
	else
	{
		l[i++] = '\n';
		l[i] = '\0';
	}
	return (l);
}

char	*grest(char *str)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = ft_strlen(str, 1);
	if (!str[i])
		return (free(str), NULL);
	r = malloc((ft_strlen(str, 0) + 1 - i) * sizeof(char));
	if (!r)
		return (NULL);
	i++;
	while (str[i])
		r[j++] = str[i++];
	r[j] = '\0';
	free(str);
	return (r);
}

char	*ft_helper(int fd, t_handle_bonus *handle, char **str)
{
	while (handle->check != 0)
	{
		handle->check = read(fd, handle->buf, BUFFER_SIZE);
		if (handle->check == -1)
		{
			free(*str);
			*str = NULL;
			return (free(handle->buf), NULL);
		}
		handle->buf[handle->check] = '\0';
		*str = ft_strjoin(*str, handle->buf);
		if (!(*str))
			return (NULL);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(handle->buf);
	handle->d = gline(*str);
	*str = grest(*str);
	return (handle->d);
}

char	*get_next_line(int fd)
{
	t_handle_bonus	handle;
	static char		*str[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	handle.buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!handle.buf)
		return (NULL);
	handle.check = 1;
	return (ft_helper(fd, &handle, &str[fd]));
}
