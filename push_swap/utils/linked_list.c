/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:14:30 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/13 09:00:29 by mkhairal         ###   ########.fr       */
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
	node->sorted = 0;
	node->maxed = 0;
	return (node);
}

void	add_front(t_stack **head, t_stack *node)
{
	t_stack	*last;

	last = NULL;
	if (*head != NULL)
	{
		last = get_last(head);
		last->nxt = node;
	}
	else
		*head = node;
	return ;
}

void	freelst(t_stack *lst)
{
	t_stack	*tmp;

	if (lst == NULL)
		return ;
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

t_stack	*get_last(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp->nxt)
		tmp = tmp->nxt;
	return (tmp);
}

t_stack	*get_before_last(t_stack **head)
{
	t_stack	*tmp;

	if (!head)
		return (NULL);
	tmp = *head;
	if (!tmp)
		return (NULL);
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
