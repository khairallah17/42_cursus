/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:16:42 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/15 19:09:44 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker(t_stack **stack_a, t_stack **stack_b, char **instructions)
{
	(void)stack_a;
	(void)stack_b;
	(void)instructions;
	return ;
}

int	instructions_checker(char *str)
{
	if (!str)
		return (0);
	else if (!ft_strcmp(str, "sa\n"))
		return (1);
	else if (!ft_strcmp(str, "sb\n"))
		return (1);
	else if (!ft_strcmp(str, "ss\n"))
		return (1);
	else if (!ft_strcmp(str, "pa\n"))
		return (1);
	else if (!ft_strcmp(str, "pb\n"))
		return (1);
	else if (!ft_strcmp(str, "ra\n"))
		return (1);
	else if (!ft_strcmp(str, "rb\n"))
		return (1);
	else if (!ft_strcmp(str, "rr\n"))
		return (1);
	else if (!ft_strcmp(str, "rra\n"))
		return (1);
	else if (!ft_strcmp(str, "rrb\n"))
		return (1);
	else if (!ft_strcmp(str, "rrr\n"))
		return (1);
	return (0);
}

void	execute_instructions(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!str)
		return ;
	else if (!ft_strcmp(str, "sa\n"))
		return (sa(stack_a));
	else if (!ft_strcmp(str, "sb\n"))
		return (sb(stack_b));
	else if (!ft_strcmp(str, "ss\n"))
		return (ss(stack_a, stack_a));
	else if (!ft_strcmp(str, "pa\n"))
		return (pa(stack_a, stack_b));
	else if (!ft_strcmp(str, "pb\n"))
		return (pb(stack_a, stack_b));
	else if (!ft_strcmp(str, "ra\n"))
		return (ra(stack_a));
	else if (!ft_strcmp(str, "rb\n"))
		return (rb(stack_b));
	else if (!ft_strcmp(str, "rr\n"))
		return (rr(stack_a, stack_b));
	else if (!ft_strcmp(str, "rra\n"))
		return (rra(stack_a));
	else if (!ft_strcmp(str, "rrb\n"))
		return (rrb(stack_b));
	else if (!ft_strcmp(str, "rrr\n"))
		return (rrr(stack_a, stack_b));
	return ;
}
