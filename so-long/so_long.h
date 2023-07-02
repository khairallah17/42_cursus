/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:40:01 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/01 14:40:58 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# define WIN_W 1
# define WIN_H 1
# define BUFFER_SIZE 4096

typedef struct h_mlx {
	void	*mlx;
	void	*mlx_win;
	void	*ply;
	void	*wall;
	void	*loot;
	void	*bg;
	void	*exit;
	char	*map;
	int		h;
	int		w;
	int		px;
	int		py;
	int		moves;
}	t_mlx;

typedef struct h_map {
	char	**map;
	char	**check1;
	char	**check2;
	int		obstacles;
	int		player;
	int		exit;
	int		collectibles;
	int		wall;
	int		free_space;
	int		tracker;
	int		height;
	int		width;
	int		cc;
	int		ec;
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		opx;
	int		opy;
}	t_map;

typedef struct h_player {
	int		x;
	int		y;
	char	*st;
}	t_player;

typedef struct h_utils{
	t_player	*player;
	t_mlx		*mlx;
	t_map		*map;
}	t_utils;

int		handle_key_press(int key, void *params);
void	initialize_game(t_utils *utils);
void	increment_and_print(int *to_inc, int inc_val, int *mvs);
void	quit_game(t_mlx *mlx);
int		parse_map(t_mlx *mlx, t_map *map);
int		check_for_rectangle(t_map *map);
int		check_for_invalid_characters(char *str, t_map *map);
int		check_closed_map(t_map *map);
char	*get_next_line(int fd);
void	flood_fill(char **map, int x, int y, t_map *maps);
void	get_player_position(t_map *map);
int		check_chars(char c, t_map *map);
int		check_for_new_line(char *str);
int		display_error_message(char *str);
t_mlx	*_init_mlx(t_mlx *mlx, t_map *map);
void	_init_player_files(t_player *player);
void	_init_utils(t_utils *utils);
void	open_and_render(t_utils *utils, int x, int y, char *img);
void	render_player(t_utils *utils);
void	fill_obstacles(t_utils *utils);
void	render_loot(t_utils *utils);
void	render_exit(t_utils *utils);
void	re_render(t_utils *utils, int key);
void	render_pixel(t_utils *utils);
char	*ft_strjoin(const char	*s1, const char	*s2);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *t);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	win(t_mlx *mlx);
int		smooth_quit(void *params);

#endif