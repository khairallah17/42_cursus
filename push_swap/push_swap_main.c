/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:30:44 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 00:38:13 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f(void)
{
	system("leaks push_swap");
}

void	print_index(t_stack **head)
{
	t_stack *tmp;

	tmp  = *head;
	while (tmp)
	{
		printf("NUMBER ==> %d || INDEX ==> %d\n", tmp->num, tmp->sorted);
		tmp = tmp->nxt;
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_stack	*head;
	t_stack	*head_b;
	char	*numbers_list;
	char	**numbers;
	int		i;

	atexit(f);
	i = 1;
	head = NULL;
	head_b = NULL;
	numbers_list = NULL;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (!is_empty(av[i]))
				quite_exit();
			numbers_list = ft_strjoin(numbers_list, av[i++]);
			free(numbers_list);
			numbers_list = ft_strjoin(numbers_list, " ");
			free(numbers_list);
		}
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
