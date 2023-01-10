/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:09:48 by mkhairal          #+#    #+#             */
/*   Updated: 2022/10/23 16:26:18 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest,	const char	*src,	unsigned int size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	counter;

	counter = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (d_len > size)
		return (size + s_len);
	while (dest[i] && i < size)
		i++;
	while (src[counter] && i < size - 1)
		dest[i++] = src[counter++];
	if (size != 0 && size >= d_len)
		dest[i] = '\0';
	if (size < d_len)
		return (s_len + size);
	return (d_len + s_len);
}
