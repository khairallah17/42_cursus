/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 04:03:06 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/13 10:12:25 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_min(t_stack **head)
{
	t_stack	*tmp;
	int		position;

	tmp = *head;
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

void	position_sort_case1(t_stack **stack_a, int position)
{
	if (position == 1)
		sa(stack_a);
	else if (position == 2)
	{	
		rra(stack_a);
		rra(stack_a);
	}
	else if (position == 3)
		rra(stack_a);
}

void	position_sort_case2(t_stack **stack_a, int position)
{
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
}

void	sort_helper(t_stack **stack_a, t_stack **stack_b, int position)
{
	position_sort_case1(stack_a, position);
	pb(stack_a, stack_b);
	hard_coded(stack_a);
	pa(stack_a, stack_a);
	pa(stack_a, stack_a);
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
			break;
		}
		tmp = tmp->nxt;
	}
	return ;
}
