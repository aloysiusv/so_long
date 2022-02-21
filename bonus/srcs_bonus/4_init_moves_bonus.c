/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:29:54 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/21 21:32:44 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes_bonus/so_long_bonus.h"

void	update_frodo_moves_2(t_game *game)
{
	if (game->nb_frodo == 1)
	{
		if (game->frodo_move_left == 1)
		{
			if (game->map[game->frodo_y][game->frodo_x - 1] != '1')
			{
				game->frodo_x -= 1;
				game->frodo_moves++;
			}
		}
		else if (game->frodo_move_right == 1)
		{
			if (game->map[game->frodo_y][game->frodo_x + 1] != '1')
			{
				game->frodo_x += 1;
				game->frodo_moves++;
			}
		}
	}
}

void	update_frodo_moves(t_game *game)
{
	if (game->nb_frodo == 1)
	{
		if (game->frodo_move_up == 1)
		{
			if (game->map[game->frodo_y - 1][game->frodo_x] != '1')
			{
				game->frodo_y -= 1;
				game->frodo_moves++;
			}
		}
		else if (game->frodo_move_down == 1)
		{
			if (game->map[game->frodo_y + 1][game->frodo_x] != '1')
			{
				game->frodo_y += 1;
				game->frodo_moves++;
			}
		}
		update_frodo_moves_2(game);
	}
}

static void	update_gollum_moves_2(t_game *game)
{
	if (game->nb_gollum == 1)
	{
		if (game->gollum_move_left == 1)
		{
			if (game->map[game->gollum_y][game->gollum_x - 1] != '1')
			{
				game->gollum_x -= 1;
				game->gollum_moves++;
			}
		}
		else if (game->gollum_move_right == 1)
		{
			if (game->map[game->gollum_y][game->gollum_x + 1] != '1')
			{
				game->gollum_x += 1;
				game->gollum_moves++;
			}
		}
	}
}

void	update_gollum_moves(t_game *game)
{
	if (game->nb_gollum == 1)
	{
		if (game->gollum_move_up == 1)
		{
			if (game->map[game->gollum_y - 1][game->gollum_x] != '1')
			{
				game->gollum_y -= 1;
				game->gollum_moves++;
			}
		}
		else if (game->gollum_move_down == 1)
		{
			if (game->map[game->gollum_y + 1][game->gollum_x] != '1')
			{
				game->gollum_y += 1;
				game->gollum_moves++;
			}
		}
		update_gollum_moves_2(game);
	}
}

void	update_orc_moves(t_game *game)
{
	if (game->nb_orc == 1)
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
}
