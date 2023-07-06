/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:14:30 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/06 22:52:14 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_node(int number)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->num = number;
	node->nxt = NULL;
	node->prv = NULL;
	return (node);
}

void	add_front(t_stack **head, t_stack *node)
{
	if (*head != NULL)
	{
		node->nxt = *head;
		(*head)->prv = node;
	}
	*head = node;
	return ;
}

void	freelst(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (lst && lst->nxt)
	{
		tmp = lst->nxt;
		free(lst);
		lst = tmp;
	}
	if (lst)
		free(lst);
}

t_stack	*get_last(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->nxt->nxt)
		tmp = tmp->nxt;

	return (tmp);
}

void	print(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp)
	{
		printf("%d, ", tmp->num);
		tmp = tmp->nxt;
	}
}
