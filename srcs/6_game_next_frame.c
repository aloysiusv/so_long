/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_game_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:46:01 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/16 18:11:02 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	print_moves(t_game *game)
{
	if (game->move_up == 1 || game->move_down == 1 || game->move_left == 1
		|| game->move_right == 1)
	{
		game->moves++;
		ft_putstr_fd("Moves = ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	update_moves(t_game *game)
{
	if (game->move_up == 1)
	{
		if (game->map[game->frodo_y - 1][game->frodo_x] != '1')
			game->frodo_y -= 1;
	}
	else if (game->move_down == 1)
	{
		if (game->map[game->frodo_y + 1][game->frodo_x] != '1')
			game->frodo_y += 1;
	}
	else if (game->move_left == 1)
	{
		if (game->map[game->frodo_y][game->frodo_x - 1] != '1')
			game->frodo_x -= 1;
	}
	else if (game->move_right == 1)
	{
		if (game->map[game->frodo_y][game->frodo_x + 1] != '1')
			game->frodo_x += 1;
	}
	print_moves(game);
}

void	update_frodo_state(t_game *game)
{
	if (game->map[game->frodo_y][game->frodo_x] == 'C')
	{
		game->taken++;
		game->map[game->frodo_y][game->frodo_x] = '0';
	}
	else if (game->map[game->frodo_y][game->frodo_x] == 'E')
	{
		if (game->taken == game->nb_swords)
			mlx_loop_end(game->mlx);
	}
}

static void	display_textures(t_game *game, int i, int j)
{
	if (game->frodo_x == j && game->frodo_y == i)
		draw_texture(game->mlx_img, j * IMG_W,
			i * IMG_H, game->textures[FRODO]);
	else if (game->map[i][j] == '1')
	{
		if (i == 0 || i == game->height - 1 || j == 0 || j == game->width - 1)
			draw_texture(game->mlx_img,
				j * IMG_W, i * IMG_H, game->textures[WALL_1]);
		else
			draw_texture(game->mlx_img,
				j * IMG_W, i * IMG_H, game->textures[WALL_2]);
	}
	else if (game->map[i][j] == 'E')
		draw_texture(game->mlx_img, j * IMG_W,
			i * IMG_H, game->textures[EXIT]);
	else if (game->map[i][j] == 'C')
		draw_texture(game->mlx_img, j * IMG_W,
			i * IMG_H, game->textures[SWORD]);
	else
		draw_canvas(game->mlx_img, j * IMG_W, i * IMG_H, 0x00000000);
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
			display_textures(game, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
}
