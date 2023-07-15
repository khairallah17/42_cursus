/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 04:03:06 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/15 08:57:09 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_min(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tmp1;
	int		position;

	tmp = *head;
	tmp1 = tmp->nxt;
	position = 0;
	while (tmp)
	{
		if (tmp->sorted == 0)
			break ;
		tmp = tmp->nxt;
		position++;
	}
	return (position);
}

void	position_sort_case1(t_stack **stack_a, t_stack **stack_b)
{
	int	position;

	sort_index(stack_a);
	position = search_min(stack_a);
	if (position == 1)
		sa(stack_a);
	else if (position == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (position == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
}

void	position_sort_case2(t_stack **stack_a, t_stack **stack_b)
{
	int	position;

	sort_index(stack_a);
	position = search_min(stack_a);
	if (position == 1)
		sa(stack_a);
	else if (position == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (position == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (position == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
}

void	max_it(t_stack **head, int num)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->num == num)
		{
			tmp->maxed = 1;
			break ;
		}
		tmp = tmp->nxt;
	}
	return ;
}
