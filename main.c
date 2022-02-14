/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:42:47 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/13 18:10:58 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
 
int	main(int ac, char *av[])
{
	t_game		game;

	if (ac != 2)
	{
        ft_putstr_fd("Error\nInvalid arguments\n", 2);
        return (1);
	}
	if (is_map_valid(&game, av[1]) == -1)
	{
        ft_putstr_fd("Error\nInvalid map\n", 2);
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
