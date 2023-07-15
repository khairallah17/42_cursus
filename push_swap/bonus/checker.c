/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:42:38 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/15 20:55:12 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*join_params(char **av, int ac)
{
	char	*tmp;
	char	*numbers_list;
	int		i;

	i = 1;
	tmp = NULL;
	numbers_list = NULL;
	while (i < ac)
	{
		if (!is_empty(av[i]))
			quite_exit();
		tmp = numbers_list;
		numbers_list = ft_strjoin(numbers_list, av[i++]);
		free(tmp);
		tmp = numbers_list;
		numbers_list = ft_strjoin(numbers_list, " ");
		free(tmp);
	}
	return (numbers_list);
}

void	global_checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*ins;
	int		check;

	ins = NULL;
	check = 1;
	while (check)
	{
		ins = get_next_line(0);
		check = instructions_checker(ins);
		execute_instructions(stack_a, stack_b, ins);
		free(ins);
	}
	if (is_sorted(stack_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
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
			global_checker(&head, &head_b);
		free(numbers_list);
		freelst(head);
		freelst(head_b);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
