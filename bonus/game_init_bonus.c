/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:37:41 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/14 14:48:34 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		printf("Error: failed to initialise mlx\n");
		return (-1);
	}
	game->mlx_win = mlx_new_window(game->mlx, game->width * IMG_W, game->height * IMG_H, "so_long");
	if (game->mlx_win == NULL)
	{
		printf("Error: failed to create new window\n");
		return (-1);
	}
	game->mlx_img = mlx_new_image(game->mlx, game->width * IMG_W, game->height * IMG_H);
	if (game->mlx_img == NULL)
	{
		printf("Error: failed to create new image\n");
		return (-1);
	}
	if (load_textures(game) == -1)
		return (-1);
	return (0);
}
