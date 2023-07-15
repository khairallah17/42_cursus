/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:31:25 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 23:20:53 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_full(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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
	free_full(str);
	return (head);
}

void	quite_exit(void)
{
	ft_putstr("Error\n");
	exit(0);
}
