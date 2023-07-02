/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:27:23 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/01 14:41:56 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_mlx	*_init_mlx(t_mlx *mlx, t_map *map)
{
	int	win_h;
	int	win_w;

	win_h = map->height * 32;
	win_w = map->width * 32;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return ((void *)0);
	mlx->mlx_win = mlx_new_window(mlx->mlx, win_w, win_h, "so_short!");
	if (!mlx->mlx_win)
		return ((void *)0);
	return (mlx);
}

void	_init_utils(t_utils *utils)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	_init_player_files(player);
	utils->player = player;
	return ;
}

void	_init_player_files(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->st = ft_strdup("textures/hero/hero_face.xpm");
}
