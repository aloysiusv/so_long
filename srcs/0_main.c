/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:42:47 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/24 04:35:37 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	init_struct(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < NB_TXTR)
		game->textures[i++] = NULL;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->mlx_img = NULL;
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->moves = 0;
	game->nb_player = 0;
	game->nb_swords = 0;
	game->nb_exits = 0;
	game->taken = 0;
	game->move_up = 0;
	game->move_down = 0;
	game->move_left = 0;
	game->move_right = 0;
}

int	main(int ac, char *av[])
{
	t_game		game;

	if (ac != 2)
	{
		ft_putstr_fd("Error:\ninvalid arguments\n", 2);
		return (1);
	}
	init_struct(&game);
	if (is_map_valid(&game, av[1]) == -1)
	{
		ft_putstr_fd("Error:\ninvalid map\n", 2);
		free_all(&game);
		return (1);
	}
	if (init_game(&game) == -1)
	{
		ft_putstr_fd("Error:\ncan't initialise game\n", 2);
		free_all(&game);
		return (1);
	}
	launch_game(&game);
	free_all(&game);
	return (0);
}
