/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:16:10 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/09 15:26:33 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **head)
{
	rotate(head);
	ft_putstr("ra\n");
}

void	rb(t_stack **head)
{
	rotate(head);
	ft_putstr("rb\n");
}

void	rra(t_stack **head)
{
	reverse_rotate(head);
	ft_putstr("rra\n");
}

void	rrb(t_stack **head)
{
	reverse_rotate(head);
	ft_putstr("rrb\n");
}
