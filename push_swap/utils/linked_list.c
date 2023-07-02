/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:14:30 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/02 16:52:41 by mkhairal         ###   ########.fr       */
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
	static int	counter;

	printf("THIS IS TIME %d\n", counter);
	counter++;
	if (*head != NULL)
	{
		node->nxt = *head;
		(*head)->prv = node;
	}
	*head = node;
	return ;
}
