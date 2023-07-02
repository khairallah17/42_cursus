/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:34:31 by mkhairal          #+#    #+#             */
/*   Updated: 2023/06/26 21:19:08 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	_init(t_map *map)
{
	map->free_space = 0;
	map->wall = 0;
	map->collectibles = 0;
	map->obstacles = 0;
	map->exit = 0;
	map->player = 0;
	map->height = 0;
	map->ec = 0;
	map->cc = 0;
}

int	checker(t_map *map, char *buffer)
{
	if (!buffer)
		return ((display_error_message("EMPTY MAP!!")));
	if (!check_for_new_line(buffer))
		return (display_error_message("EMPTY LINE DETECTED!!"));
	if (!check_for_invalid_characters(buffer, map))
		return (0);
	map->map = ft_split(buffer, '\n');
	map->check1 = ft_split(buffer, '\n');
	map->check2 = ft_split(buffer, '\n');
	free(buffer);
	if (!check_closed_map(map) || !check_for_rectangle(map))
		return (0);
	get_player_position(map);
	flood_fill(map->map, map->px, map->py, map);
	if (map->ec != map->exit || map->cc != map->collectibles)
		return (display_error_message("MAP HAS NO VALID PATH!!"));
	return (1);
}

int	parse_map(t_mlx *mlx, t_map *map)
{
	int			file;
	char		*buffer;
	char		*temp;
	char		*gnl;

	buffer = NULL;
	file = open(mlx->map, O_RDONLY);
	if (file == -1)
		return (display_error_message("INVALID FILE PATH"));
	gnl = get_next_line(file);
	while (gnl)
	{
		temp = buffer;
		buffer = ft_strjoin(buffer, gnl);
		free(temp);
		free(gnl);
		gnl = get_next_line(file);
	}
	free(gnl);
	_init(map);
	if (!checker(map, buffer))
		exit(display_error_message("Error"));
	return (1);
}
