/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:16:05 by mkhairal          #+#    #+#             */
/*   Updated: 2022/11/02 10:29:39 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*nxt;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		nxt = current->next;
		(*del)(current->content);
		free(current);
		current = nxt;
	}
	*lst = NULL;
}
