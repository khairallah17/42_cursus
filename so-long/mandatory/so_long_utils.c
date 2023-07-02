/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:41:01 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/01 14:29:25 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	quit_game(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

void	increment_and_print(int *to_inc, int inc_val, int *mvs)
{
	*to_inc += inc_val;
	*mvs += 1;
	ft_putstr("CURRENT NUMBER OF MOVES ==> ");
	ft_putnbr(*mvs);
	ft_putstr("\n");
}

void	open_and_render(t_utils *utils, int x, int y, char *img)
{
	t_mlx	*mlx;

	mlx = utils->mlx;
	mlx->bg = mlx_xpm_file_to_image(mlx->mlx, img, &mlx->w, &mlx->h);
	if (!mlx->bg)
	{
		ft_putstr("NO IMG SELECTED!!\n");
		ft_putstr("Error\n");
		quit_game(mlx);
	}
	else
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->bg, x, y);
	return ;
}

void	fill_obstacles(t_utils *utils)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = utils->map;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '1')
				open_and_render(utils, j * 32, i * 32, "textures/env/obs.xpm");
			j++;
		}
		i++;
	}
	return ;
}

int	smooth_quit(void *params)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)params;
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (0);
}
