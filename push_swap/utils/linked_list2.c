/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:43:02 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/10 02:47:06 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_size(t_stack **head)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	if (!head)
		return (0);
	if (*head == NULL)
		return (0);
	tmp = *head;
	while (tmp)
	{
		tmp = tmp->nxt;
		size++;
	}
	return (size);
}

int	get_node_position(t_stack **head, int number)
{
	t_stack	*tmp;
	int		i;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		if (tmp->num == number)
			break ;
		i++;
		tmp = tmp->nxt;
	}
	return (i);
}

void	sort_index(t_stack **head)
{
	t_stack	*big;
	t_stack	*small;
	int		position;

	if (!head)
		return ;
	big = *head;
	while (big)
	{
		position = 0;
		small = *head;
		while (small)
		{
			if (small->num < big->num)
				position++;
			small = small->nxt;
		}
		big->sorted = position;
		big = big->nxt;
	}
}

int	is_sorted(t_stack **head)
{
	t_stack	*tmp;
	int		sub;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (0);
	tmp = *head;
	sub = 0;
	while (tmp->nxt)
	{
		sub = tmp->sorted - tmp->nxt->sorted;
		if (ft_abs(sub) != 1)
			return (0);
		tmp = tmp->nxt;
	}
	return (1);
}

int	get_position(t_stack **head, int number)
{
	t_stack	*tmp;
	int		pos;

	pos = 0;
	tmp = *head;
	while (tmp)
	{
		if (tmp->num == number)
			return (pos);
		pos++;
		tmp = tmp->nxt;
	}
	return (pos);
}
