/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_map_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:42:47 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/16 21:53:11 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

static int borders_or_chars_and_keep_count(t_game *game, int i, int j)
{
	if (i == 0 || i == game->height - 1 || j == 0 || j == game->width - 1)
	{
		if (game->map[i][j] != '1')
			return (-1);
	}
	if (game->map[i][j] == 'P')
	{
		game->frodo_y = i;
		game->frodo_x = j;
		game->map[i][j] = '0';
		game->nb_players++;
	}
	else if (game->map[i][j] == 'G')
	{
		game->gollum_y = i;
		game->gollum_x = j;
		game->map[i][j] = '0';
		game->nb_players++;
	}
	else if (game->map[i][j] == 'X')
	{
		game->orc_y = i;
		game->orc_x = j;
		game->map[i][j] = '0';
		game->nb_players++;
	}
	else if (game->map[i][j] == 'C')
		game->nb_swords++;
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
	if (game->nb_swords < 1 || game->nb_exits < 1 || game->nb_players < 1)
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
	if (check_extension(".ber", filename) == -1)
	{
		printf("Wrong ext.\n");
		return (-1);
	}
	if (get_map(game, filename) == -1)
	{
		printf("Unable to get map.\n");
		return (-1);
	}
	if (check_map(game) == -1)
	{
		printf("Problem in map.\n");
		return (-1);
	}
	return (0);
}
