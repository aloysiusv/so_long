/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_init_txtr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:37:41 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/19 15:16:35 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

static int	textures_inanimate(t_game *game)
{
	const char	*out_wall_txt = "./assets_bonus/wall_1.xpm";
	const char	*in_wall_txt = "./assets_bonus/wall_2.xpm";
	const char	*sword_txt = "./assets_bonus/sword.xpm";
	int			img_width;
	int			img_height;

	img_width = IMG_W;
	img_height = IMG_H;
	game->txtr[WALL_1] = mlx_xpm_file_to_image(game->mlx,
			(char *)out_wall_txt, &img_width, &img_height);
	if (game->txtr[WALL_1] == NULL)
		return (-1);
	game->txtr[WALL_2] = mlx_xpm_file_to_image(game->mlx,
			(char *)in_wall_txt, &img_width, &img_height);
	if (game->txtr[WALL_2] == NULL)
		return (-1);
	game->txtr[SWORD] = mlx_xpm_file_to_image(game->mlx,
			(char *)sword_txt, &img_width, &img_height);
	if (game->txtr[SWORD] == NULL)
		return (-1);
	return (0);
}

static int	textures_orcs_exit(t_game *game)
{
	const char	*orc_right_txt = "./assets_bonus/orc_right.xpm";
	const char	*orc_left_txt = "./assets_bonus/orc_left.xpm";
	const char	*exit_txt = "./assets_bonus/door.xpm";
	int			img_width;
	int			img_height;

	img_width = IMG_W;
	img_height = IMG_H;
	game->txtr[ORC_RGT] = mlx_xpm_file_to_image(game->mlx,
			(char *)orc_right_txt, &img_width, &img_height);
	if (game->txtr[ORC_RGT] == NULL)
		return (-1);
	game->txtr[ORC_LFT] = mlx_xpm_file_to_image(game->mlx,
			(char *)orc_left_txt, &img_width, &img_height);
	if (game->txtr[ORC_LFT] == NULL)
		return (-1);
	game->txtr[EXIT] = mlx_xpm_file_to_image(game->mlx,
			(char *)exit_txt, &img_width, &img_height);
	if (game->txtr[EXIT] == NULL)
		return (-1);
	return (0);
}

static int	load_textures(t_game *game)
{
	const char	*frodo_txt = "./assets_bonus/frodo.xpm";
	const char	*gollum_txt = "./assets_bonus/gollum.xpm";
	int			img_width;
	int			img_height;

	img_width = IMG_W;
	img_height = IMG_H;
	game->txtr[FRODO] = mlx_xpm_file_to_image(game->mlx,
			(char *)frodo_txt, &img_width, &img_height);
	if (game->txtr[FRODO] == NULL)
		return (-1);
	game->txtr[GOLLUM] = mlx_xpm_file_to_image(game->mlx,
			(char *)gollum_txt, &img_width, &img_height);
	if (game->txtr[GOLLUM] == NULL)
		return (-1);
	if (textures_orcs_exit(game) == -1)
		return (-1);
	if (textures_inanimate(game) == -1)
		return (-1);
	return (0);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (-1);
	game->mlx_win = mlx_new_window(game->mlx, game->width * IMG_W,
			game->height * IMG_H, "so_long");
	if (game->mlx_win == NULL)
		return (-1);
	game->mlx_img = mlx_new_image(game->mlx, game->width * IMG_W,
			game->height * IMG_H);
	if (game->mlx_img == NULL)
		return (-1);
	if (load_textures(game) == -1)
		return (-1);
	return (0);
}
