/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:15 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/14 14:49:52 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define ESC		65307

# define W			119
# define S			115
# define A			97
# define D			100

# define UP			65362
# define DOWN		65364
# define LEFT		65361
# define RIGHT		65363

# define IMG_W		40
# define IMG_H		40

# define CODE_KEY_PRESS_MASK		2, 1L << 0
# define CODE_KEY_RELEASE_MASK		3, 1L << 1
# define CODE_DESTROY_NOTIFY_MASK	17, 1L << 17

enum	e_textures
{
	WALL_1,
	WALL_2,
	EXIT,
	COLLECTS,
	FRODO,
	GOLLUM,
	NB_TXTR
};

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_img		*mlx_img;
	t_img		*textures[NB_TXTR];
	char		**map;
	int			width;
	int			height;
	int			frodo_x;
	int			frodo_y;
	int			gollum_x;
	int			gollum_y;
	size_t		moves;
	size_t		nb_player;
	size_t		nb_collects;
	size_t		nb_exits;
	size_t		taken;			
	int			frodo_move_up;
	int			frodo_move_down;
	int			frodo_move_left;
	int			frodo_move_right;
	int			gollum_move_up;
	int			gollum_move_down;
	int			gollum_move_left;
	int			gollum_move_right;
}				t_game;


int		is_map_valid(t_game *game, char *filename);
int		get_map(t_game *game, char *filename);
void	print_map(char **map, size_t width, size_t height);

int		init_game(t_game *game);
void	launch_game(t_game *game);
void	display_frame(t_game *game);

int		load_textures(t_game *game);
void	draw_texture(t_img *mlx_img, int x, int y, t_img *texture);
void	draw_canvas(t_img *mlx_img, int x, int y, int size, int colour);



void	free_all(t_game *game);

#endif