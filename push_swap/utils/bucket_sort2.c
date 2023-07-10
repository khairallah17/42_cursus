/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 02:19:41 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/10 02:46:51 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	top_and_push(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int	size;
	int	i;

	size = list_size(stack_b);
	i = get_position(stack_b, pos);
	if (i > size / 2)
	{
		while (i++ < size)
			rrb(stack_b);
	}
	else if (i < size / 2)
	{
		while (i-- > 0)
			rb(stack_b);
	}
	if (*sb)
		pa(stack_a, stack_b);
}
