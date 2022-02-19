/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_game_start_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:19:59 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/19 18:14:54 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

static int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		mlx_loop_end(game->mlx);
	else if (keycode == W)
		game->frodo_move_up = 1;
	else if (keycode == S)
		game->frodo_move_down = 1;
	else if (keycode == A)
		game->frodo_move_left = 1;
	else if (keycode == D)
		game->frodo_move_right = 1;
	else if (keycode == UP)
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

static void	print_moves(t_game *game, char *name, int moves, int x)
{
	char	*player_moves;
	char	*player_str;

	player_moves = ft_itoa(moves);
	if (player_moves == NULL)
		return ;
	player_str = ft_strjoin(name, player_moves);
	if (player_str == NULL)
	{
		free(player_moves);
		return ;
	}
	mlx_string_put(game->mlx, game->mlx_win, x, 30, 0xCCCCCC, player_str);
	free(player_str);
	free(player_moves);
}

static int	render_next_frame(t_game *game)
{
	static int	i = 0;
	const int	g_w_first = game->width * PIX_SIZE / 4;
	const int	g_w_last = g_w_first * 3;

	if (i++ % 5 == 0)
	{
		update_frodo_moves(game);
		update_gollum_moves(game);
		update_orc_moves(game);
	}
	update_players_state(game);
	display_frame(game);
	print_moves(game, "FRODO = ", game->frodo_moves, g_w_first);
	print_moves(game, "GOLLUM = ", game->gollum_moves, g_w_last);
	return (0);
}

void	launch_game(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_key_press, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, ft_key_release, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, mlx_loop_end, game->mlx);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_do_key_autorepeatoff(game->mlx);
	mlx_loop(game->mlx);
	mlx_do_key_autorepeaton(game->mlx);
}
