/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_game_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:37:41 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/19 15:21:44 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	textures_inanimate(t_game *game)
{
	const char	*out_wall_txt = "./assets/wall.xpm";
	const char	*in_wall_txt = "./assets/ground.xpm";
	const char	*sword_txt = "./assets/sword.xpm";
	int			img_width;
	int			img_height;

	img_width = IMG_W;
	img_height = IMG_H;
	game->textures[WALL_1] = mlx_xpm_file_to_image(game->mlx,
			(char *)out_wall_txt, &img_width, &img_height);
	if (game->textures[WALL_1] == NULL)
		return (-1);
	game->textures[WALL_2] = mlx_xpm_file_to_image(game->mlx,
			(char *)in_wall_txt, &img_width, &img_height);
	if (game->textures[WALL_2] == NULL)
		return (-1);
	game->textures[SWORD] = mlx_xpm_file_to_image(game->mlx,
			(char *)sword_txt, &img_width, &img_height);
	if (game->textures[SWORD] == NULL)
		return (-1);
	return (0);
}

static int	load_textures(t_game *game)
{
	const char	*player_txt = "./assets/player.xpm";
	const char	*exit_txt = "./assets/door.xpm";
	int			img_width;
	int			img_height;

	img_width = IMG_W;
	img_height = IMG_H;
	if (textures_inanimate(game) == -1)
		return (-1);
	game->textures[FRODO] = mlx_xpm_file_to_image(game->mlx,
			(char *)player_txt, &img_width, &img_height);
	if (game->textures[FRODO] == NULL)
		return (-1);
	game->textures[EXIT] = mlx_xpm_file_to_image(game->mlx,
			(char *)exit_txt, &img_width, &img_height);
	if (game->textures[EXIT] == NULL)
		return (-1);
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
	game->mlx_win = mlx_new_window(game->mlx,
			game->width * IMG_W, game->height * IMG_H, "so_long");
	if (game->mlx_win == NULL)
	{
		printf("Error: failed to create new window\n");
		return (-1);
	}
	game->mlx_img = mlx_new_image(game->mlx,
			game->width * IMG_W, game->height * IMG_H);
	if (game->mlx_img == NULL)
	{
		printf("Error: failed to create new image\n");
		return (-1);
	}
	if (load_textures(game) == -1)
		return (-1);
	return (0);
}
