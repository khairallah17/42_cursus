/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:44:04 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/09 23:33:58 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if ((*head)->nxt == NULL)
		return ;
	tmp1 = *head;
	tmp2 = (*head)->nxt;
	*head = tmp2;
	tmp1->nxt = (*head)->nxt;
	(*head)->nxt = tmp1;
}

void	rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;

	if ((*head)->nxt == NULL)
		return ;
	tmp = *head;
	last = get_last(head);
	last->nxt = *head;
	*head = tmp->nxt;
	tmp->nxt = NULL;
}

void	reverse_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*tmp;

	if ((*head)->nxt == NULL)
		return ;
	tmp = *head;
	last = get_before_last(head);
	*head = last->nxt;
	last->nxt = NULL;
	(*head)->nxt = tmp;
}

void	push(t_stack **head, t_stack **node)
{
	t_stack	*tmp;

	if (!head || !node)
		return ;
	if (!*node)
		return ;
	tmp = *head;
	*head = *node;
	*node = (*node)->nxt;
	(*head)->nxt = tmp;
}
