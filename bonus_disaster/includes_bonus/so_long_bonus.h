/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:15 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/17 21:31:55 by lrandria         ###   ########.fr       */
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

enum	e_textures
{
	WALL_1,
	WALL_2,
	EXIT,
	SWORD,
	FRODO,
	GOLLUM,
	ORC_RIGHT,
	ORC_LEFT,
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
	int			orc_x;
	int			orc_y;
	int			orc_dir;		
	size_t		moves;
	size_t		nb_players;
	size_t		nb_swords;
	size_t		nb_exits;
	size_t		taken;			
	int			frodo_move_up;
	int			frodo_move_down;
	int			frodo_move_left;
	int			frodo_move_right;
	int			frodo_moves;
	int			gollum_move_up;
	int			gollum_move_down;
	int			gollum_move_left;
	int			gollum_move_right;
	int			gollum_moves;
}				t_game;


int		is_map_valid(t_game *game, char *filename);
int		get_map(t_game *game, char *filename);
void	print_map(char **map, size_t width, size_t height);

int		init_game(t_game *game);
void	launch_game(t_game *game);
void	display_frame(t_game *game);

void	update_frodo_moves(t_game *game);
void	update_gollum_moves(t_game *game);
void	update_orc_moves(t_game *game);
void	update_players_state(t_game *game);
void	print_moves(t_game *game);


void	draw_texture(t_img *mlx_img, int x, int y, t_img *texture);
void	draw_canvas(t_img *mlx_img, int x, int y, int size, int colour);

void	free_all(t_game *game);

#endif