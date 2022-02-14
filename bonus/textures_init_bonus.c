/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:47:37 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/14 15:04:18 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	textures_building(t_game *game)
{
	const char	*out_wall_txt = "./assets/wall_1.xpm";
	const char	*in_wall_txt = "./assets/wall_2.xpm";
	const char	*exit_txt = "./assets/door.xpm";
	int			img_width;
	int			img_height;
	
	img_width = 40;
	img_height = 40;
	game->textures[WALL_1] = mlx_xpm_file_to_image(game->mlx, (char *)out_wall_txt, &img_width, &img_height);
	if (game->textures[WALL_1] == NULL)
		return (-1);
	game->textures[WALL_2] = mlx_xpm_file_to_image(game->mlx, (char *)in_wall_txt, &img_width, &img_height);
	if (game->textures[WALL_2] == NULL)
		return (-1);
	game->textures[EXIT] = mlx_xpm_file_to_image(game->mlx, (char *)exit_txt, &img_width, &img_height);
	if (game->textures[EXIT] == NULL)
		return (-1);

	return (0);
}
static int	textures_chara(t_game *game)
{
	const char	*frodo_txt = "./assets/frodo.xpm";
	const char	*gollum_txt = "./assets/gollum.xpm";
	// const char	*dragon_txt = "./assets/dragon.xpm";
	int			img_width;
	int			img_height;

	img_width = 40;
	img_height = 40;
	game->textures[FRODO] = mlx_xpm_file_to_image(game->mlx, (char *)frodo_txt, &img_width, &img_height);
	if (game->textures[FRODO] == NULL)
		return (-1);
	game->textures[GOLLUM] = mlx_xpm_file_to_image(game->mlx, (char *)gollum_txt, &img_width, &img_height);
	if (game->textures[GOLLUM] == NULL)
		return (-1);
	// game->textures[DRAGON] = mlx_xpm_file_to_image(game->mlx, (char *)dragon_txt, &img_width, &img_height);
	// if (game->textures[DRAGON] == NULL)
	// 	return (-1);
	return (0);
}

static int textures_collects(t_game *game)
{
	// const char	*ring_txt = "./assets/ring.xpm";
	const char	*collects_txt = "./assets/sword.xpm";
	int			img_width;
	int			img_height;

	img_width = 40;
	img_height = 40;
	game->textures[COLLECTS] = mlx_xpm_file_to_image(game->mlx, (char *)collects_txt, &img_width, &img_height);
	if (game->textures[COLLECTS] == NULL)
		return (-1);
	// game->textures[RING] = mlx_xpm_file_to_image(game->mlx, (char *)ring_txt, &img_width, &img_height);
	// if (game->textures[RING] == NULL)
	// 	return (-1);
	return (0);
}
	
int	load_textures(t_game *game)
{
	if (textures_building(game) == -1)
		return (-1);
	if (textures_chara(game) == -1)
		return (-1);
	if (textures_collects(game) == -1)
		return (-1);
	return (0);
}