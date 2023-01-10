/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:13:43 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/30 00:36:21 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# define HEXADECIMAL "0123456789abcdef"
# define HEX "0123456789ABCDEF"
# define PRE "0x"

int		get_nbr_length(int n);
char	*ft_itoa(int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(unsigned long n);
int		ft_print_address(unsigned int number, int cap);
int		ft_print_hex(unsigned long long number);
int		ft_printf(const char *s, ...);
void	ft_handle(char *s, va_list *lst, int *len);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strlen(char *s);
int		ft_handle_u(unsigned long nb);
int		ft_handle_p(unsigned long long nb);
int		ft_handle_x(unsigned long nb, int cap);
int		ft_handle_d_i(int d);
int		ft_handle_s(char *str);
int		ft_handle_c(char *d);

#endif