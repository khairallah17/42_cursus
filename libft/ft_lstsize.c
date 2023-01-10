/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:40:24 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/16 13:22:23 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*s;

	i = 0;
	s = lst;
	if (s == NULL)
		return (0);
	while (s != NULL)
	{
		i++;
		s = s->next;
	}
	return (i);
}
