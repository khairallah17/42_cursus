/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:06:23 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/15 10:38:25 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_stack **sa, t_stack **sb)
{
	swap(sa);
	swap(sb);
}

void	rr(t_stack **sa, t_stack **sb)
{
	rotate(sa);
	rotate(sb);
}

void	rrr(t_stack **sa, t_stack **sb)
{
	reverse_rotate(sa);
	reverse_rotate(sb);
}

void	sa(t_stack **head)
{
	swap(head);
}

void	sb(t_stack **head)
{
	swap(head);
}
