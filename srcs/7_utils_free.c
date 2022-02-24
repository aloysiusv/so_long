/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_utils_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:09:51 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/24 04:21:40 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (game->mlx != NULL && game->textures[i] != NULL && i < NB_TXTR)
		mlx_destroy_image(game->mlx, game->textures[i++]);
	if (game->mlx_img != NULL)
		mlx_destroy_image(game->mlx, game->mlx_img);
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
		while (i <= game->height)
		{
			if (game->map[i] != NULL)
				free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}
