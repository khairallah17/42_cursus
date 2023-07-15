/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:35:20 by hasalam           #+#    #+#             */
/*   Updated: 2023/03/25 17:54:55 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1042
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct n_handle_bonus
{
	char	*d;
	char	*buf;
	int		check;
}	t_handle_bonus;

char	*grest(char *str);
char	*gline(char *str);
char	*get_next_line(int fd);
int		ft_strlen(char *str, int flag);
char	*ft_strjoin(char *str, char *buf);
char	*ft_strchr(char *str, int c);

#endif