/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:30:44 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/02 16:52:11 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f(void)
{
	system("leaks push_swap");
}

void freelst(t_stack *lst)
{
	t_stack *tmp;
	
	tmp = lst;
	while (lst && lst->nxt)
	{
		tmp = lst->nxt;
		free(lst);
		lst = tmp;
	}
	if (lst)
		free(lst);
}

int	main(int ac, char *av[])
{
	char	**numbers_list;
	t_stack	*head;

	// atexit(f);
	numbers_list = NULL;
	head = NULL;
	if (ac == 2)
	{
		numbers_list = ft_split(av[1], ' ');
		head = _init_stack(numbers_list);
		freelst(head);
		free(numbers_list);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
