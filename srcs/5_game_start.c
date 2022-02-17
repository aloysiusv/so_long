/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_game_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:19:59 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/17 19:33:31 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		mlx_loop_end(game->mlx);
	else if (keycode == UP)
		game->move_up = 1;
	else if (keycode == DOWN)
		game->move_down = 1;
	else if (keycode == LEFT)
		game->move_left = 1;
	else if (keycode == RIGHT)
		game->move_right = 1;
	return (0);
}

static int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == UP)
		game->move_up = 0;
	else if (keycode == DOWN)
		game->move_down = 0;
	else if (keycode == LEFT)
		game->move_left = 0;
	else if (keycode == RIGHT)
		game->move_right = 0;
	return (0);
}

void	print_moves(t_game *game)
{
	if (game->move_up == 1 || game->move_down == 1
		|| game->move_left == 1 || game->move_right == 1)
	{
		printf("Moves = %zu\r", game->moves);
		fflush(stdout);
	}
}

static int	render_next_frame(t_game *game)
{
	static int	i = 0;

	if (i++ % 5 == 0)
		update_moves(game);
	print_moves(game);
	update_frodo_state(game);
	display_frame(game);
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
