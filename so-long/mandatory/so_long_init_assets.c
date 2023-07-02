/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_assets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:29:49 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/01 14:45:16 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_multiple_images(void	*params)
{
	int			i;
	t_player	*player;

	i = 0;
	player = (t_player *)params;
	while (i < 5)
	{
		i++;
	}
	return (0);
}

void	render_loot(t_utils *utils)
{
	t_map	*map;
	t_mlx	*mlx;
	int		i;
	int		j;

	i = 0;
	map = utils->map;
	mlx = utils->mlx;
	if (map->check1[map->px][map->py] == 'C')
	{
		map->check1[map->px][map->py] = 'X';
		map->collectibles -= 1;
	}
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->check1[i][j] == 'C')
				open_and_render(utils, j * 32, i * 32, "textures/env/loot.xpm");
			j++;
		}
		i++;
	}
	return ;
}

void	render_exit(t_utils *utils)
{
	t_mlx	*mlx;
	t_map	*map;
	char	*img;
	int		x;
	int		y;

	mlx = utils->mlx;
	map = utils->map;
	x = map->ey * 32;
	y = map->ex * 32;
	img = "textures/env/door_closed.xpm";
	if (map->collectibles == 0)
	{
		map->exit -= 1;
		img = "textures/env/door_open.xpm";
	}
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, img, &mlx->w, &mlx->h);
	if (!mlx->exit)
	{
		ft_putstr("NO IMG SELECTED!!\n");
		ft_putstr("Error\n");
		quit_game(mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->exit, x, y);
	return ;
}

void	render_pixel(t_utils *utils)
{
	t_map	*map;
	t_mlx	*mlx;
	char	*img;
	int		x;
	int		y;

	map = utils->map;
	mlx = utils->mlx;
	x = map->opy * 32;
	y = map->opx * 32;
	if (!x && !y)
		return ;
	img = "textures/env/bg-sm.xpm";
	mlx->ply = mlx_xpm_file_to_image(mlx->mlx, img, &mlx->w, &mlx->h);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ply, x, y);
	if (map->check1[map->opx][map->opy] == 'E')
		render_exit(utils);
	return ;
}

void	render_player(t_utils *utils)
{
	t_mlx		*mlx;
	t_player	*ply;
	t_map		*map;
	int			x;
	int			y;

	map = utils->map;
	mlx = utils->mlx;
	ply = utils->player;
	x = map->py * 32;
	y = map->px * 32;
	render_pixel(utils);
	if (map->collectibles == 0 && map->check1[map->px][map->py] == 'E')
		win(mlx);
	mlx->ply = mlx_xpm_file_to_image(mlx->mlx, ply->st, &mlx->w, &mlx->h);
	if (!mlx->ply)
	{
		ft_putstr("NO IMG SELECTED!!\nError\n");
		quit_game(mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ply, x, y);
	return ;
}
