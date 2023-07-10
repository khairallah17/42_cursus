/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:06:23 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/09 15:27:49 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack **sa, t_stack **sb)
{
	swap(sa);
	swap(sb);
	ft_putstr("ss\n");
}

void	rr(t_stack **sa, t_stack **sb)
{
	rotate(sa);
	rotate(sb);
	ft_putstr("rr\n");
}

void	rrr(t_stack **sa, t_stack **sb)
{
	reverse_rotate(sa);
	reverse_rotate(sb);
	ft_putstr("rrr\n");
}

void	sa(t_stack **head)
{
	swap(head);
	ft_putstr("sa\n");
}

void	sb(t_stack **head)
{
	swap(head);
	ft_putstr("sb\n");
}
