/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:16:10 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/15 10:51:05 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack **head)
{
	rotate(head);
}

void	rb(t_stack **head)
{
	rotate(head);
}

void	rra(t_stack **head)
{
	reverse_rotate(head);
}

void	rrb(t_stack **head)
{
	reverse_rotate(head);
}
