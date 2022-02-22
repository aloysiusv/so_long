/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_game_next_frame_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:16:31 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/22 15:59:13 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes_bonus/so_long_bonus.h"

static void	game_end(t_game *game, char *message)
{
	ft_putstr_fd(message, 1);
	mlx_loop_end(game->mlx);
}

void	update_players_state(t_game *game)
{
	if (game->map[game->frodo_y][game->frodo_x] == 'C')
	{
		game->taken++;
		game->map[game->frodo_y][game->frodo_x] = '0';
	}
	else if (game->map[game->gollum_y][game->gollum_x] == 'C')
	{
		game->taken++;
		game->map[game->gollum_y][game->gollum_x] = '0';
	}
	else if (game->frodo == 1 && game->frodo_y == game->orc_y
		&& (game->frodo_x == game->orc_x
			|| game->frodo_x == game->orc_x + 1
			|| game->frodo_x == game->orc_x - 1))
		game_end(game, "\033[1;31mGAME OVER\n\033[0m");
	else if ((game->frodo == 1
			&& game->map[game->frodo_y][game->frodo_x] == 'E')
			|| (game->gollum == 1 && game->map[game->gollum_y][game->gollum_x]
			== 'E'))
		if (game->taken == game->nb_swords)
			game_end(game, "\033[0;32mWELL DONE\n\033[0m");
}

static void	display_more_elements(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		if (i == 0 || i == game->height - 1 || j == 0 || j == game->width - 1)
			draw_txtr(game->mlx_img, j * IMG_W, i * IMG_H, game->txtr[WALL_1]);
		else
			draw_txtr(game->mlx_img, j * IMG_W, i * IMG_H, game->txtr[WALL_2]);
	}
	else if (game->map[i][j] == 'E')
		draw_txtr(game->mlx_img, j * IMG_W, i * IMG_H, game->txtr[EXIT]);
	else if (game->map[i][j] == 'C')
		draw_txtr(game->mlx_img, j * IMG_W, i * IMG_H, game->txtr[SWORD]);
}

static void	display_elements(t_game *game, int i, int j)
{
	if (game->nb_orc == 1 && game->orc_x == j && game->orc_y == i)
	{
		if (game->orc_dir == 1)
			draw_txtr(game->mlx_img, j * IMG_W, i * IMG_H, game->txtr[ORC_LFT]);
		else
			draw_txtr(game->mlx_img, j * IMG_W, i * IMG_H, game->txtr[ORC_RGT]);
	}
	else if (game->map[i][j] == '1' || (game->map[i][j] == 'E')
			|| (game->map[i][j] == 'C'))
		display_more_elements(game, i, j);
	else
		draw_canvas(game->mlx_img, j * IMG_W, i * IMG_H, 0x00000000);
	if (game->frodo == 1 && game->frodo_x == j && game->frodo_y == i)
		draw_player(game->mlx_img, j * IMG_W, i * IMG_H, game->txtr[FRODO]);
	if (game->gollum && game->gollum_x == j && game->gollum_y == i)
		draw_player(game->mlx_img, j * IMG_W, i * IMG_H, game->txtr[GOLLUM]);
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
