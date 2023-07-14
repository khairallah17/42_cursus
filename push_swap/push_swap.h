/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:30:40 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 00:36:35 by mkhairal         ###   ########.fr       */
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
	int				sorted;
	int				maxed;
	struct h_stack	*nxt;
}	t_stack;

typedef struct h_maximus {
	int	max1;
	int	pos1;
	int	max2;
	int	pos2;
}	t_maximus;

int		ft_atoi(const char *nptr);
void	ft_putnbr(int n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char	*s1, const char	*s2);
void	ft_putstr(char *s);
t_stack	*create_node(int number);
void	add_front(t_stack **head, t_stack *node);
int		how_many_numbers(char **str);
int		check_splitable(char *str);
int		*convert_to_int(char **str, int size);
t_stack	*_init_stack(char **str);
void	freelst(t_stack *lst);
t_stack	*get_last(t_stack **head);
void	swap(t_stack **head);
void	rotate(t_stack **head);
void	reverse_rotate(t_stack **head);
void	print(t_stack **head);
t_stack	*get_before_last(t_stack **head);
int		ft_strcmp(const char *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *t);
int		check_invalid_chars(char **str);
int		list_size(t_stack **head);
void	push(t_stack **head, t_stack **node);
int		ft_abs(int num);
int		is_sorted(t_stack **head);
int		get_node_position(t_stack **head, int number);
void	sort_index(t_stack **head);
int		check_duplicates(int *tab, int size);
int		check_for_max_int(char **str);
void	quite_exit(void);
void	sa(t_stack **head);
void	sb(t_stack **head);
void	ss(t_stack **sa, t_stack **sb);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	rr(t_stack **sa, t_stack **sb);
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	rrr(t_stack **sa, t_stack **sb);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b, int b_size, int o_size);
void	split_bucket(t_stack **stack_a, t_stack **stack_b, int size);
void	buckets(t_stack **stack_a, t_stack **stack_b);
void	top_and_push(t_stack **stack_a, t_stack **stack_b, int pos);
void	sort(t_stack **stack_a, t_stack **stack_b, int b_size, int o_size);
void	split_bucket(t_stack **stack_a, t_stack **stack_b, int size);
void	get_two_maxs(t_stack **head, t_maximus **maxs);
void	final_sort(t_stack **stack_a, t_stack **stack_b);
void	buckets(t_stack **stack_a, t_stack **stack_b);
int		get_position(t_stack **head, int number);
void	top_and_push(t_stack **stack_a, t_stack **stack_b, int pos);
void	hard_coded(t_stack **head);
void	sort4(t_stack **stack_a, t_stack **stack_b);
void	sort5(t_stack **stack_a, t_stack **stack_b);
void	small_size_sort(t_stack **stack_a, t_stack **stack_b, int size);
int		search_min(t_stack **head);
void	position_sort_case1(t_stack **stack_a, int position);
void	position_sort_case2(t_stack **stack_a, int position);
void	sort_helper(t_stack **stack_a, t_stack **stack_b, int position);
void	max_it(t_stack **head, int num);
void	print_index(t_stack **head);
int		is_empty(char *str);
int		is_number(char c);
int		is_signe(char c);
void	free_full(char **str);

#endif