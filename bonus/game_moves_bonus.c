/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:19:59 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/14 16:27:34 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		mlx_loop_end(game->mlx);
	else if (keycode == W )
		game->frodo_move_up = 1;
	else if (keycode == S)
		game->frodo_move_down = 1;
	else if (keycode == A)
		game->frodo_move_left = 1;
	else if (keycode == D)
		game->frodo_move_right = 1;
	else if (keycode == UP )
		game->gollum_move_up = 1;
	else if (keycode == DOWN)
		game->gollum_move_down = 1;
	else if (keycode == LEFT)
		game->gollum_move_left = 1;
	else if (keycode == RIGHT)
		game->gollum_move_right = 1;
	return (0);
}

static int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->frodo_move_up = 0;
	else if (keycode == S)
		game->frodo_move_down = 0;
	else if (keycode == A)
		game->frodo_move_left = 0;
	else if (keycode == D)
		game->frodo_move_right = 0;
	if (keycode == UP)
		game->gollum_move_up = 0;
	else if (keycode == DOWN)
		game->gollum_move_down = 0;
	else if (keycode == LEFT)
		game->gollum_move_left = 0;
	else if (keycode == RIGHT)
		game->gollum_move_right = 0;
	return (0);
}

static void	update_frodo_moves(t_game *game)
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

static void	update_gollum_moves(t_game *game)
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
		if (game->taken == game->nb_collects)
			mlx_loop_end(game->mlx);
	}
}

static int	render_next_frame(t_game *game)
{
	static int i = 0;
	
	if (i++ % 5 == 0)
	{
		update_frodo_moves(game);
		update_gollum_moves(game);
	}
	update_players_state(game);
	display_frame(game);
	return (0);
}

void	launch_game(t_game *game)
{
	mlx_hook(game->mlx_win, CODE_KEY_PRESS_MASK, ft_key_press, game);
	mlx_hook(game->mlx_win, CODE_KEY_RELEASE_MASK, ft_key_release, game);
	mlx_hook(game->mlx_win, CODE_DESTROY_NOTIFY_MASK, mlx_loop_end, game->mlx);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_do_key_autorepeatoff(game->mlx);
	mlx_loop(game->mlx);
	mlx_do_key_autorepeaton(game->mlx);
}
