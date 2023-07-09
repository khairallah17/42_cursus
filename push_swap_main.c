/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:30:44 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/09 18:30:20 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f(void)
{
	system("leaks push_swap");
}

int	main(int ac, char *av[])
{
	t_stack	*head;
	t_stack	*head_b;
	char	*numbers_list;
	char	**numbers;
	int		i;

	// atexit(f);
	i = 1;
	head = NULL;
	head_b = NULL;
	numbers_list = NULL;
	if (ac > 1)
	{
		while (i < ac)
		{
			printf("%s\n", av[i]);
			numbers_list = ft_strjoin(numbers_list, av[i++]);
			numbers_list = ft_strjoin(numbers_list, " ");
		}
		numbers = ft_split(numbers_list, ' ');
		check_invalid_chars(numbers);
		head = _init_stack(numbers);
		// print(&head);
		sort_index(&head);
		buckets(&head, &head_b);
		printf("BEFORE STACK B\n");
		// print(&head_b);
		printf("AFTER STACK B\n");
		// freelst(head);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
