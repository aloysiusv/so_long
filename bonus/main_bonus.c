/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:42:47 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/14 14:18:41 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	game->nb_collects = 0;
	game->nb_exits = 0;
	game->taken = 0;
	game->frodo_move_up = 0;
	game->frodo_move_down = 0;
	game->frodo_move_left = 0;
	game->frodo_move_right = 0;
	game->gollum_move_up = 0;
	game->gollum_move_down = 0;
	game->gollum_move_left = 0;
	game->gollum_move_right = 0;
}

int	main(int ac, char *av[])
{
	t_game		game;

	if (ac != 2)
	{
        ft_putstr_fd("Error\nInvalid arguments\n", 2);
        return (1);
	}
	init_struct(&game);
	if (is_map_valid(&game, av[1]) == -1)
	{
        ft_putstr_fd("Error\nInvalid map\n", 2);
        free_all(&game);
		return (1);
	}
	print_map(game.map, game.width, game.height);
	if (init_game(&game) == -1)
	{	
		free_all(&game);
		return (1);
	}
	launch_game(&game);
	free_all(&game);
	return (0);
}