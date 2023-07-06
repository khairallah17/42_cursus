/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:44:04 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/06 22:37:03 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *head)
{
	t_stack	*s;

	s = head->nxt;
	head->nxt = head->nxt->nxt;
	head->nxt->nxt = s;
}

void	rotate(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = head;
	last = get_last(head);
	last->nxt = head;
	tmp->nxt->nxt = tmp->nxt;
	tmp->nxt = NULL;
}

void	reverse_rotate(t_stack *head)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = head;
	last = get_last(head);
	last->prv->nxt = NULL;
	last->nxt = head;
	head = last;
}
