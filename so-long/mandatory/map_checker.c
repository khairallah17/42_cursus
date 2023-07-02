/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:10:55 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/01 13:53:13 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int x, int y, t_map *maps)
{
	if (x < 0 || y < 0)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	if (map[x][y] == 'E')
		maps->ec += 1;
	if (map[x][y] == 'C')
		maps->cc += 1;
	map[x][y] = 'X';
	flood_fill(map, x - 1, y, maps);
	flood_fill(map, x + 1, y, maps);
	flood_fill(map, x, y - 1, maps);
	flood_fill(map, x, y + 1, maps);
}

int	check_for_rectangle(t_map *map)
{
	int	i;
	int	size;

	i = 1;
	size = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != size)
			return (display_error_message("MAP IS NOT A RECTANGLE!!"));
		i++;
	}
	if (i == size)
		return (display_error_message("MAP IS NOT A RECTANGLE!!"));
	map->height = i;
	return (1);
}

int	check_closed_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[0][++i])
		if (map->map[0][i] != '1')
			return (display_error_message("MAP NOT SURROUNDED WITH WALLS!!"));
	map->width = i - 1;
	i = -1;
	while (map->map[++i])
		if (map->map[i][0] != '1')
			return (display_error_message("MAP NOT SURROUNDED WITH WALLS!!"));
	map->height = i - 1;
	i = -1;
	while (map->map[map->height][++i])
		if (map->map[map->height][i] != '1')
			return (display_error_message("MAP NOT SURROUNDED WITH WALLS!!"));
	i = 0;
	while (i < map->height && map->map[i][map->width])
	{
		if (map->map[i][map->width] != '1')
			return (display_error_message("MAP NOT SURROUNDED WITH WALLS!!"));
		i++;
	}
	map->width += 1;
	return (1);
}

int	check_for_invalid_characters(char *str, t_map *map)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!check_chars(str[i], map))
			return (display_error_message("INVALID CHARACTERE DETECTED !!"));
		i++;
	}
	if (map->exit == 0)
		return (display_error_message("THERE IS NO EXIT DETECTED!!"));
	if (map->exit > 1)
		return (display_error_message("MAP HAS MORE THAN AN EXIT!!"));
	if (map->player > 1)
		return (display_error_message("MAP HAS MORE THAN A PLAYER!!"));
	if (map->player == 0)
		return (display_error_message("THERE IS NO PLAYER DETECTED!!"));
	if (map->collectibles == 0)
		return (display_error_message("THERE IS NO COLLECTIBLES DETECTED!!"));
	return (1);
}
