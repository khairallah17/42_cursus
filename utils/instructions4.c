/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:20:46 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/09 18:31:33 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, *stack_b);
	ft_putstr("pa\n");
	(*stack_b) = (*stack_b)->nxt;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, *stack_a);
	ft_putstr("pb\n");
	(*stack_a) = (*stack_a)->nxt;
}
