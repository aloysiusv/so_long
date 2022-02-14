/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:41:55 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/13 17:40:47 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	// game->exits = NULL;
	// game->rings = NULL;
	game->moves = 0;
	game->nb_rings = 0;
	game->nb_exits = 0;
	game->taken = 0;
	game->move_up = 0;
	game->move_down = 0;
	game->move_left = 0;
	game->move_right = 0;
}

static int borders_or_chars_and_keep_count(t_game *game, int i, int j)
{
	if (i == 0 || i == game->height - 1 || j == 0 || j == game->width - 1)
	{
		if (game->map[i][j] != '1')
			return (-1);
	}
	else if (game->map[i][j] == 'P')
		game->nb_player++;
	else if (game->map[i][j] == 'C')
		game->nb_rings++;
	else if (game->map[i][j] == 'E')
		game->nb_exits++;
	else if (game->map[i][j] != '0' && game->map[i][j] != '1')
		return (-1);
	return (0);
}

static int	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (borders_or_chars_and_keep_count(game, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (game->nb_rings < 1 || game->nb_exits < 1 || game->nb_player != 1)
		return (-1);
	return (0);
}

static int	check_extension(char *ext, char *filename)
{
	size_t	i;
    size_t  j;
    
    if (ft_strlen(filename) < 5)
        return (-1);
    i = ft_strlen(filename) - 4;
    j = 0;
    while (ext[j])
    {
        if (ext[j] != filename[i])
            return(-1);
        i++;
        j++;
    }
	return (0);
}

int	is_map_valid(t_game *game, char *filename)
{
	init_struct(game);
	if (check_extension(".ber", filename) == -1)
		return (-1);
	if (get_map(game, filename) == -1)
		return (-1);
	if (check_map(game) == -1)
		return (-1);
	return (0);
}