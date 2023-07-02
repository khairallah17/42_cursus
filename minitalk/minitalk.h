/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:41:57 by mkhairal          #+#    #+#             */
/*   Updated: 2023/05/31 21:57:12 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_atoi(const char *ptr);
int		ft_strlen(char *s);
int		check_pid(char *str);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);

typedef struct h_unicode
{
	char			res[4];
	unsigned char	cv;
	int				nob;
	int				cp;
	int				ac;
	pid_t			cpid;
}	t_unicode;

#endif