/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:31:25 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/09 14:36:28 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*_init_stack(char **str)
{
	t_stack	*head;
	int		*tab;
	int		i;
	t_stack	*node;
	int		size;

	head = NULL;
	size = how_many_numbers(str);
	tab = convert_to_int(str, size);
	i = 0;
	if (!tab)
		return (NULL);
	while (i < size)
	{
		node = create_node(tab[i]);
		add_front(&head, node);
		i++;
	}
	free(tab);
	return (head);
}

void	quite_exit(char *str)
{
	ft_putstr(str);
	ft_putstr("Error\n");
	exit(0);
}
