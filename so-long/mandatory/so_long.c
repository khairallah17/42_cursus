/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:47:53 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/01 14:38:21 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_key_press(int key, void *params)
{
	t_utils	*utils;
	t_mlx	*mlx;
	t_map	*map;

	utils = (t_utils *)params;
	mlx = utils->mlx;
	map = utils->map;
	map->opx = map->px;
	map->opy = map->py;
	if (key == 1 && map->map[map->px + 1][map->py] != '1')
		increment_and_print(&map->px, 1, &mlx->moves);
	else if (key == 13 && map->map[map->px - 1][map->py] != '1')
		increment_and_print(&map->px, -1, &mlx->moves);
	else if (key == 0 && map->map[map->px][map->py - 1] != '1')
		increment_and_print(&map->py, -1, &mlx->moves);
	else if (key == 2 && map->map[map->px][map->py + 1] != '1')
		increment_and_print(&map->py, 1, &mlx->moves);
	else if (key == 53)
		quit_game(mlx);
	else
		return (0);
	re_render(utils, key);
	return (0);
}

int	main(int ac, char *av[])
{
	t_mlx		mlx;
	t_map		map;
	t_utils		utils;

	if (ac == 2)
	{
		mlx.moves = 0;
		mlx.px = 0;
		mlx.py = 0;
		mlx.map = av[1];
		if (!parse_map(&mlx, &map))
			exit(display_error_message("Error"));
		utils.mlx = _init_mlx(&mlx, &map);
		if (!utils.mlx)
			return (display_error_message("UNABLE TO INITIALIZE GAME"));
		utils.map = &map;
		_init_utils(&utils);
		initialize_game(&utils);
		mlx_key_hook(mlx.mlx_win, handle_key_press, (void *)&utils);
		mlx_hook(mlx.mlx_win, 17, 0, smooth_quit, (void *)&mlx);
		mlx_loop(mlx.mlx);
	}
	else
		ft_putstr("INVALID NUMBER OF ARGUMENTS");
	return (0);
}
