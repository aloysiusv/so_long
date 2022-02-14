/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:37:41 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/13 18:30:41 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	walls_exit_ring(t_game *game)
{
	const char	*wall_txt = "./assets/awesome_wall.xpm";
	const char	*exit_txt = "./assets/awesome_door.xpm";
	const char	*ring_txt = "./assets/collectible_1.xpm";
	int			img_width;
	int			img_height;
	
	img_width = 40;
	img_height = 40;
	game->textures[WALL] = mlx_xpm_file_to_image(game->mlx, (char *)wall_txt, &img_width, &img_height);
	if (game->textures[WALL] == NULL)
		return (-1);
	game->textures[EXIT] = mlx_xpm_file_to_image(game->mlx, (char *)exit_txt, &img_width, &img_height);
	if (game->textures[EXIT] == NULL)
		return (-1);
	game->textures[RING] = mlx_xpm_file_to_image(game->mlx, (char *)ring_txt, &img_width, &img_height);
	if (game->textures[RING] == NULL)
		return (-1);
	return (0);
}

static int	load_textures(t_game *game)
{
	const char	*player_txt = "./assets/awesome_player.xpm";
	// const char	*enemy_txt = "./assets/awesome_enemy.xpm";
	int			img_width;
	int			img_height;
	
	img_width = 40;
	img_height = 40;
	if (walls_exit_ring(game) == -1)
		return (-1);
	game->textures[FRODO] = mlx_xpm_file_to_image(game->mlx, (char *)player_txt, &img_width, &img_height);
	if (game->textures[FRODO] == NULL)
		return (-1);
	// game->textures[ENEMY] = mlx_xpm_file_to_image(game->mlx, (char *)enemy_txt, IMG_W, IMG_H);
	// if (game->textures[ENEMY] == NULL)
	// 	return (-1);
	return (0);
}

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
