/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 02:19:41 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/15 08:56:24 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	top_and_push(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int	size;
	int	i;

	size = list_size(stack_b);
	i = get_position(stack_b, pos);
	if (i > (size / 2))
	{
		while (i++ < size)
			rrb(stack_b);
	}
	else if (i <= (size / 2))
	{
		while (i-- > 0)
			rb(stack_b);
	}
	if (*sb)
		pa(stack_a, stack_b);
}

void	hard_coded(t_stack **head)
{
	t_stack	*tmp;
	/*use 3 variables for compration*/

	tmp = *head;
	if (tmp->sorted < tmp->nxt->sorted && tmp->nxt->nxt->sorted > tmp->sorted
		&& tmp->nxt->sorted > tmp->nxt->nxt->sorted)
	{
		rra(head);
		sa(head);
	}
	else if (tmp->sorted > tmp->nxt->sorted
		&& tmp->nxt->nxt->sorted < tmp->sorted
		&& tmp->nxt->sorted > tmp->nxt->nxt->sorted)
	{
		sa(head);
		rra(head);
	}
	else if (tmp->sorted < tmp->nxt->sorted
		&& tmp->nxt->sorted > tmp->nxt->nxt->sorted
		&& tmp->nxt->nxt->sorted < tmp->sorted)
		rra(head);
	else if (tmp->sorted > tmp->nxt->sorted
		&& tmp->nxt->nxt->sorted < tmp->sorted)
		ra(head);
	else if (tmp->sorted > tmp->nxt->sorted 
		&& tmp->nxt->sorted < tmp->nxt->nxt->sorted
		&& tmp->nxt->nxt->sorted > tmp->sorted)
		sa(head);
	return ;
}

void	sort4(t_stack **stack_a, t_stack **stack_b)
{
	position_sort_case1(stack_a, stack_b);
	hard_coded(stack_a);
	pa(stack_a, stack_b);
	return ;
}

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	position_sort_case2(stack_a, stack_b);
	sort4(stack_a, stack_b);
	pa(stack_a, stack_b);
	return ;
}

void	small_size_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sa(stack_a);
	if (size == 3)
		hard_coded(stack_a);
	else if (size == 4)
		sort4(stack_a, stack_b);
	else if (size == 5)
		sort5(stack_a, stack_b);
}
