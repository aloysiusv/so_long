/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_game_next_frame_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:16:31 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/17 22:01:46 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

// void	print_moves(t_game *game)
// {
// 	if (game->frodo_move_up == 1 || game->frodo_move_down == 1 || game->frodo_move_left == 1
// 		|| game->frodo_move_right == 1)
// 	{
// 		game->frodo_moves++;
// 		mlx_string_put(game->mlx, game->mlx_win, 0, 0, 0x000CC,
// 			ft_strjoin("Frodo: ", ft_itoa(game->frodo_moves)));
// 	}
// 	if (game->gollum_move_up == 1 || game->gollum_move_down == 1 || game->gollum_move_left == 1
// 		|| game->gollum_move_right == 1)
// 	{
// 		game->gollum_moves++;
// 		mlx_string_put(game->mlx, game->mlx_win,
//                 game->width - 3, 0, 0x000CC, ft_strjoin("Gollum: ", ft_itoa(game->gollum_moves)));
// 	}
// }

void	update_frodo_moves(t_game *game)
{
	if (game->frodo_move_up == 1)
	{
		if (game->map[game->frodo_y - 1][game->frodo_x] != '1')
			game->frodo_y -= 1;
	}
	else if (game->frodo_move_down == 1)
	{
		if (game->map[game->frodo_y + 1][game->frodo_x] != '1')
			game->frodo_y += 1;
	}
	else if (game->frodo_move_left == 1)
	{
		if (game->map[game->frodo_y][game->frodo_x - 1] != '1')
			game->frodo_x -= 1;
	}
	else if (game->frodo_move_right == 1)
	{
		if (game->map[game->frodo_y][game->frodo_x + 1] != '1')
			game->frodo_x += 1;
	}
}

void	update_gollum_moves(t_game *game)
{
	if (game->gollum_move_up == 1)
	{
		if (game->map[game->gollum_y - 1][game->gollum_x] != '1')
			game->gollum_y -= 1;
	}
	else if (game->gollum_move_down == 1)
	{
		if (game->map[game->gollum_y + 1][game->gollum_x] != '1')
			game->gollum_y += 1;
	}
	else if (game->gollum_move_left == 1)
	{
		if (game->map[game->gollum_y][game->gollum_x - 1] != '1')
			game->gollum_x -= 1;
	}
	else if (game->gollum_move_right == 1)
	{
		if (game->map[game->gollum_y][game->gollum_x + 1] != '1')
			game->gollum_x += 1;
	}
}

void	update_orc_moves(t_game *game)
{
	if (game->orc_dir == 0)
	{
		if (game->map[game->orc_y][game->orc_x + 1] != '1') 
			game->orc_x++;
		else
			game->orc_dir = 1;
	}
	else
	{
		if (game->map[game->orc_y][game->orc_x -1] != '1') 
        	game->orc_x--;
		else
			game->orc_dir = 0;
	}
}

void	update_players_state(t_game *game)
{
	if (game->map[game->frodo_y][game->frodo_x] == 'C' || 
		game->map[game->gollum_y][game->gollum_x] == 'C')
	{
		game->taken++;
		game->map[game->frodo_y][game->frodo_x] = '0';
		game->map[game->gollum_y][game->gollum_x] = '0';
	}
	else if (game->map[game->frodo_y][game->frodo_x] == 'E' ||
		game->map[game->gollum_y][game->gollum_x] == 'E')
	{
		if (game->taken == game->nb_swords)
			mlx_loop_end(game->mlx);
	}
}

static void	display_elements(t_game *game, int i, int j)
{
	if (game->frodo_x == j && game->frodo_y == i)
		draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[FRODO]);
	else if (game->gollum_x == j && game->gollum_y == i)
		draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[GOLLUM]);
	else if (game->orc_x == j && game->orc_y == i)
	{
		if (game->orc_dir == 1)
			draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[ORC_LEFT]);
		else
			draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[ORC_RIGHT]);
	}
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
		draw_texture(game->mlx_img, j * IMG_W, i * IMG_H, game->textures[SWORD]);
	else
		draw_canvas(game->mlx_img, j * IMG_W, i * IMG_H, 40, 0x00000000);
	// print_moves(game);
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
	mlx_string_put(game->mlx, game->mlx_win, 200, 200, 0xCC0000, "FRODO MOVES = ");
	mlx_string_put(game->mlx, game->mlx_win, 400, 400, 0xCC0000, "GOLLUM MOVES = ");
}
