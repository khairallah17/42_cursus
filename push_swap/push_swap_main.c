/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:30:44 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/06 22:51:20 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f(void)
{
	system("leaks push_swap");
}

int	main(int ac, char *av[])
{
	char	**numbers_list;
	t_stack	*head;
	t_stack	*last;

	// atexit(f);
	numbers_list = NULL;
	head = NULL;
	last = NULL;
	if (ac == 2)
	{
		numbers_list = ft_split(av[1], ' ');
		head = _init_stack(numbers_list);
		printf("===================== INIT STATE =====================\n");
		print(&head);
		// swap(head);
		// printf("===================== AFTER SWAP =====================\n");
		// print(head);
		freelst(head);
		free(numbers_list);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
