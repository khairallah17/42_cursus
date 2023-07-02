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

int	main(int ac, char *av[])
{
	char	**numbers_list;
	t_stack	*head;
	int		i;

	// atexit(f);
	numbers_list = NULL;
	head = NULL;
	i = -1;
	if (ac == 2)
	{
		numbers_list = ft_split(av[1], ' ');
		while (numbers_list[++i])
			printf("str %d ==> %s\n", i, numbers_list[i]);
		head = _init_stack(numbers_list);
		free(numbers_list);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
