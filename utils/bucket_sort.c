/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:05:49 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/09 18:37:19 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b, int b_size, int o_size)
{
	while ((*stack_a)->sorted >= b_size)
	{
		printf("LOOP STACK_A\n");
		ra(stack_a);
	}
	if ((*stack_a)->sorted <= b_size - (o_size / 2))
	{
		printf("PUSH STACK B\n");
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->sorted > b_size - (o_size / 2))
	{
		printf("STACK A STACK B ELSE IF\n");
		pb(stack_a, stack_b);
		if ((*stack_a)->sorted >= b_size)
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
		printf("STACK A ==> ");
		print(stack_a);
		printf("\n");
		printf("STACK B ==> ");
		print(stack_b);
		printf("\n");
		sort(stack_a, stack_b, size, nbuckets);
		if (list_size(stack_b) == size)
			size += nbuckets;
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
		return ;
	else
		split_bucket(stack_a, stack_b, size);
}
