/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:33:39 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/01 14:28:22 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_game(t_utils *utils)
{
	t_mlx		*mlx;
	t_player	*player;
	t_map		*map;

	mlx = utils->mlx;
	player = utils->player;
	map = utils->map;
	open_and_render(utils, 0, 0, "textures/env/bg.xpm");
	fill_obstacles(utils);
	render_loot(utils);
	render_exit(utils);
	render_player(utils);
}

void	win(t_mlx *mlx)
{
	ft_putstr("YOU WIN :)!!");
	quit_game(mlx);
	return ;
}

void	re_render(t_utils *utils, int key)
{
	t_player	*player;
	t_mlx		*mlx;

	player = utils->player;
	mlx = utils->mlx;
	free(player->st);
	if (key == 1)
		player->st = ft_strdup("textures/hero/hero_face.xpm");
	if (key == 13)
		player->st = ft_strdup("textures/hero/hero_back.xpm");
	if (key == 0)
		player->st = ft_strdup("textures/hero/hero_left.xpm");
	if (key == 2)
		player->st = ft_strdup("textures/hero/hero_right.xpm");
	render_loot(utils);
	render_exit(utils);
	render_player(utils);
	return ;
}
