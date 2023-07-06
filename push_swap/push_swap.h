/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:30:40 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/06 22:49:37 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct h_stack {
	int				num;
	struct h_stack	*nxt;
	struct h_stack	*prv;
}	t_stack;

int		ft_atoi(const char *nptr);
void	ft_putnbr(int n);
char	**ft_split(const char *s, char c);
void	ft_putstr(char *s);
t_stack	*create_node(int number);
void	add_front(t_stack **head, t_stack *node);
int		how_many_numbers(char **str);
int		*convert_to_int(char **str);
t_stack	*_init_stack(char **str);
void	freelst(t_stack *lst);
t_stack	*get_last(t_stack *head);
void	swap(t_stack *head);
void	rotate(t_stack *head);
void	reverse_rotate(t_stack *head);
void	print(t_stack **head);

#endif