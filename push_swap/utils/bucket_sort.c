/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:05:49 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/13 10:43:22 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b, int b_size, int o_size)
{
	while ((*stack_a)->sorted >= b_size)
	{
		ra(stack_a);
	}
	if ((*stack_a)->sorted <= b_size - (o_size / 2))
		pb(stack_a, stack_b);
	else if ((*stack_a)->sorted > b_size - (o_size / 2))
	{
		pb(stack_a, stack_b);
		if ((*stack_a) && (*stack_a)->sorted >= b_size)
			ra(stack_a);
		rb(stack_b);
	}
}

void	split_bucket(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	nbuckets;

	nbuckets = 0;
	if (size < 20)
		size /= 2;
	else if (size <= 200)
		size /= 6;
	else if (size <= 500)
		size /= 10;
	else
		size /= 14;
	nbuckets = size;
	while (*stack_a)
	{
		sort(stack_a, stack_b, size, nbuckets);
		if (list_size(stack_b) == size)
			size += nbuckets;
	}
}

void	get_two_maxs(t_stack **head, t_maximus **maxs)
{
	t_stack	*tmp;
	int		pos;

	tmp = *head;
	pos = 0;
	while (tmp)
	{
		if ((*maxs)->max1 < tmp->num)
		{
			(*maxs)->max1 = tmp->num;
			(*maxs)->pos1 = pos;
		}
		tmp = tmp->nxt;
		pos++;
	}
	max_it(head, (*maxs)->max1);
	tmp = *head;
	pos = 0;
	while (tmp)
	{
		if ((*maxs)->max2 < tmp->num && tmp->maxed != 1)
		{
			(*maxs)->max2 = tmp->num;
			(*maxs)->pos2 = pos;
		}
		tmp = tmp->nxt;
		pos++;
	}
	max_it(head, (*maxs)->max2);
}

void	final_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_maximus	*maxs;

	maxs = (t_maximus *)malloc(sizeof(t_maximus));
	maxs->max1 = INT_MIN;
	maxs->max2 = INT_MIN + 1;
	maxs->pos1 = 0;
	maxs->pos2 = 0;
	get_two_maxs(stack_b, &maxs);
	if (maxs->pos2 > (list_size(stack_b) / 2))
		maxs->pos2 = list_size(stack_b) - maxs->pos2;
	if (maxs->pos1 > (list_size(stack_b) / 2))
		maxs->pos1 = list_size(stack_b) - maxs->pos1;
	if (maxs->pos1 > maxs->pos2)
	{
		top_and_push(stack_a, stack_b, maxs->max2);
		top_and_push(stack_a, stack_b, maxs->max1);
		sa(stack_a);
	}
	else
	{
		top_and_push(stack_a, stack_b, maxs->max1);
		top_and_push(stack_a, stack_b, maxs->max2);
	}
}

void	buckets(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (*stack_a == NULL)
		return ;
	size = list_size(stack_a);
	if (size <= 5)
	{
		small_size_sort(stack_a, stack_b, size);
	}
	else if (size > 5)
	{
		split_bucket(stack_a, stack_b, size);
		while (*stack_b)
			final_sort(stack_a, stack_b);
	}
}
