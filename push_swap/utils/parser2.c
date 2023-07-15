/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:19:46 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/14 23:49:23 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_empty(char *str)
{
	int	i;
	int	cc;

	i = 0;
	cc = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			cc++;
		i++;
	}
	return (cc);
}

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
