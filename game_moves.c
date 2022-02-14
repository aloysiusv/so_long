/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:19:59 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/13 18:42:10 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_key_press(int keycode, t_game *root)
{
	if (keycode == ESC)
		mlx_loop_end(root->mlx);
	else if (keycode == UP)
		root->move_up = 1;
	else if (keycode == DOWN)
		root->move_down = 1;
	else if (keycode == LEFT)
		root->move_left = 1;
	else if (keycode == RIGHT)
		root->move_right = 1;
	return (0);
}

static int	ft_key_release(int keycode, t_game *root)
{
	if (keycode == UP)
		root->move_up = 0;
	else if (keycode == DOWN)
		root->move_down = 0;
	else if (keycode == LEFT)
		root->move_left = 0;
	else if (keycode == RIGHT)
		root->move_right = 0;
	return (0);
}

static void	update_moves(t_game *game)
{
	if (game->move_up == 1)
	{
		if (game->map[game->frodo.y - 1][game->frodo.x] != '1')
			game->frodo.y -= 1;
		// game->move_up = 0;
	}
	else if (game->move_down == 1)
	{
		if (game->map[game->frodo.y + 1][game->frodo.x] != '1')
			game->frodo.y += 1;
		// game->move_down = 0;
	}
	else if (game->move_left == 1)
	{
		if (game->map[game->frodo.y][game->frodo.x - 1] != '1')
			game->frodo.x -= 1;
		// game->move_left = 0;
	}
	else if (game->move_right == 1)
	{
		if (game->map[game->frodo.y][game->frodo.x + 1] != '1')
			game->frodo.x += 1;
		// game->move_right = 0;
	}
}

static int	render_next_frame(t_game *game)
{
	update_moves(game);
	display_frame(game);
	return (0);
}

void	launch_game(t_game *game)
{
	mlx_hook(game->mlx_win, CODE_KEY_PRESS_MASK, ft_key_press, &game);
	mlx_hook(game->mlx_win, CODE_KEY_RELEASE_MASK, ft_key_release, &game);
	mlx_hook(game->mlx_win, CODE_DESTROY_NOTIFY_MASK, mlx_loop_end, game->mlx);
	mlx_loop_hook(game->mlx, render_next_frame, &game);
	// mlx_do_key_autorepeatoff(game->mlx);
	mlx_loop(game->mlx);
	// mlx_do_key_autorepeaton(game->mlx);
}
