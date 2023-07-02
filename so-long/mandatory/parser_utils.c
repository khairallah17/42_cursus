/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:19:31 by mkhairal          #+#    #+#             */
/*   Updated: 2023/06/26 20:41:39 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_chars(char c, t_map *map)
{
	if (c == '0')
		map->free_space += 1;
	else if (c == '1')
		map->wall += 1;
	else if (c == 'E')
		map->exit += 1;
	else if (c == 'P')
		map->player += 1;
	else if (c == 'C')
		map->collectibles += 1;
	else if (c != '\n')
		return (0);
	return (1);
}

void	get_player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				map->px = i;
				map->py = j;
			}
			else if (map->check1[i][j] == 'E')
			{
				map->ex = i;
				map->ey = j;
			}
			j++;
		}
		i++;
	}
}

int	check_for_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		else if (str[i] == '\n' && i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	display_error_message(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
	return (0);
}
