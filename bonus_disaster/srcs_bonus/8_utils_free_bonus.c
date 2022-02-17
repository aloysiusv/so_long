/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_utils_free_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:19:59 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/17 19:57:56 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (i < NB_TXTR)
	{
		printf("hello\n");
		mlx_destroy_image(game->mlx, game->textures[i++]);
	}
	if (game->mlx_img != NULL)
	{
		printf("hello2\n");
		mlx_destroy_image(game->mlx, game->mlx_img);
	}
	if (game->mlx_win != NULL)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map != NULL)
	{
		i = 0;
		while (i < game->height && game->map[i] != NULL)
			free(game->map[i++]);
		free(game->map);
	}
}
