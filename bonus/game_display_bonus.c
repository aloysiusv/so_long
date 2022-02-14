/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:16:31 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/14 16:28:33 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	display_elements(t_game *game, int i, int j)
{
	if (game->frodo_x == j && game->frodo_y == i)
		draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[FRODO]);
	else if (game->gollum_x == j && game->gollum_y == i)
		draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[GOLLUM]);
	else if (game->map[i][j] == '1')
	{
		if (i == 0 || i == game->height - 1 || j == 0 || j == game->width - 1)
			draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[WALL_1]);
		else
			draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[WALL_2]);
	}
	else if (game->map[i][j] == 'E')
		draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[EXIT]);
	else if (game->map[i][j] == 'C')
		draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[COLLECTS]);
	else 
		draw_canvas(game->mlx_img, j * IMG_W, i * IMG_H, 40, 0x00000000);
}

void	display_frame(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			display_elements(game, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
}
