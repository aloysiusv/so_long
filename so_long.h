/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:15 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/08 15:37:56 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define ESC		65307
# define UP			119
# define DOWN		115
# define LEFT		97
# define RIGHT		100

# define CODE_KEY_PRESS_MASK		2, 1L << 0
# define CODE_KEY_RELEASE_MASK		3, 1L << 1
# define CODE_DESTROY_NOTIFY_MASK	17, 1L << 17

enum	e_textures
{
	WALL,
	GROUND,
	COLLECT_1,
	COLLECT_2,
	COLLECT_3,
	ENEMY,
	PLAYER,
	EXIT,
	NB_TXTR
};

typedef struct	s_root
{
	void	*mlx;
	void	*mlx_win;
	t_img	*mlx_img;

	t_img	*textures[NB_TXTR];
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x; // for the red square
	int		player_y; // idem
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
}				t_root;


#endif