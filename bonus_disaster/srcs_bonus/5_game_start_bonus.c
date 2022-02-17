/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_game_start_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:19:59 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/17 19:53:09 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

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

// static void	make_orc_moves(t_game *game)
// {
//     while (game->map[game->orc_y][game->orc_x + 1] != '1') 
//     {
// 		game->orc_dir = 0;
// 		game->orc_x++;
// 	}
//     if (game->map[game->orc_y][game->orc_x] == game->width - 1)
//     {
// 		game->orc_dir = 1;
// 		while (game->map[game->orc_y][game->orc_x -1] != '1') 
//         	game->orc_x--;
// 	}
// }

// static int	game_over(t_game *game)
// {
// 	if (game->map[game->frodo_y][game->frodo_x] 
//         == game->map[game->orc_y][game->orc_x - 1] || 
// 		game->map[game->frodo_y][game->frodo_x] 
//         == game->map[game->orc_y][game->orc_x + 1] ||
// 		game->map[game->gollum_y][game->gollum_x]
//         == game->map[game->orc_y][game->orc_x - 1] ||
// 		game->map[game->gollum_y][game->gollum_x] 
//         == game->map[game->orc_y][game->orc_x + 1])
//         return (1);
//     else
//         return (0);
// }

static int	render_next_frame(t_game *game)
{
	static int i = 0;
	
	if (i++ % 5 == 0)
	{
		update_frodo_moves(game);
		update_gollum_moves(game);
        // make_orc_moves(game);
		// if (game_over(game) == 1)
		// {
        //     mlx_string_put(game->mlx, game->mlx_win,
        //         game->height / 3, game->width / 3, 0xCC0000, "GAME OVER :(");
        //     usleep(10000);
        //     free_all(game);
        //     exit(EXIT_SUCCESS);
        // }
	}
	update_players_state(game);
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
