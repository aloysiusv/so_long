/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:15 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/13 18:38:57 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define ESC		65307
# define UP			119
# define DOWN		115
# define LEFT		97
# define RIGHT		100

# define IMG_W		40
# define IMG_H		40

# define CODE_KEY_PRESS_MASK		2, 1L << 0
# define CODE_KEY_RELEASE_MASK		3, 1L << 1
# define CODE_DESTROY_NOTIFY_MASK	17, 1L << 17

enum	e_textures
{
	WALL,
	EXIT,
	RING,
	FRODO,
	GOLLUM,
	NB_TXTR
};

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_img		*mlx_img;
	t_img		*textures[NB_TXTR];
	char		**map;
	int			width;
	int			height;
	t_pos		frodo;
	// t_pos		gollum;
	// t_pos		*exits;
	// t_pos		*rings;
	size_t		moves;
	size_t		nb_player;
	size_t		nb_rings;
	size_t		nb_exits;
	size_t		taken;			
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
}				t_game;


int		is_map_valid(t_game *game, char *filename);
int		get_map(t_game *game, char *filename);
void	print_map(char **map, size_t width, size_t height);

int		init_game(t_game *game);
void	launch_game(t_game *game);
static int		render_next_frame(t_game *game);
void	display_frame(t_game *game);

void	free_all(t_game *game);

#endif