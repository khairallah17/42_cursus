/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:31:25 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/02 16:52:50 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*_init_stack(char **str)
{
	t_stack	*head;
	int		size;
	int		*tab;
	int		i;
	t_stack	*node;

	head = NULL;
	size = how_many_numbers(str);
	tab = convert_to_int(str);
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
