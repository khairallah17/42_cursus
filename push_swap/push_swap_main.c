/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:30:44 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/15 11:38:04 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack **head)
{
	t_stack *tmp;

	tmp = *head;
	while (tmp)
	{
		printf("%d, ",tmp->num);
		tmp = tmp->nxt;
	}
	printf("\n");
}

int	main(int ac, char *av[])
{
	t_stack	*head;
	t_stack	*head_b;
	char	*numbers_list;
	char	**numbers;

	head = NULL;
	head_b = NULL;
	numbers_list = NULL;
	if (ac > 1)
	{
		numbers_list = join_params(av, ac);
		numbers = ft_split(numbers_list, ' ');
		check_invalid_chars(numbers);
		head = _init_stack(numbers);
		sort_index(&head);
		if (!is_sorted(&head))
			buckets(&head, &head_b);
		free(numbers_list);
		freelst(head);
		freelst(head_b);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
