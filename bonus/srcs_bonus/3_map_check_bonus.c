/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_map_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:52:07 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/24 14:59:25 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes_bonus/so_long_bonus.h"

static int	check_line_len(t_game *game)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len != game->width)
			return (-1);
		i++;
	}
	return (0);
}

static void	is_characters(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		game->frodo_y = i;
		game->frodo_x = j;
		game->map[i][j] = '0';
		game->frodo++;
		game->nb_players++;
	}
	else if (game->map[i][j] == 'G')
	{
		game->gollum_y = i;
		game->gollum_x = j;
		game->map[i][j] = '0';
		game->gollum++;
		game->nb_players++;
	}
	else if (game->map[i][j] == 'X')
	{
		game->orc_dir = 0;
		game->orc_y = i;
		game->orc_x = j;
		game->nb_orc++;
		game->map[i][j] = '0';
	}
}

static int	is_borders_or_chars(t_game *game, int i, int j)
{
	if (i == 0 || i == game->height - 1 || j == 0 || j == game->width - 1)
	{
		if (game->map[i][j] != '1')
			return (-1);
	}
	else if (game->map[i][j] == 'P' || game->map[i][j] == 'G'
			|| game->map[i][j] == 'X')
		is_characters(game, i, j);
	else if (game->map[i][j] == 'C')
		game->nb_swords++;
	else if (game->map[i][j] == 'E')
		game->nb_exits++;
	else if (game->map[i][j] != '0' && game->map[i][j] != '1')
		return (-1);
	return (0);
}

int	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (is_borders_or_chars(game, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (game->nb_swords < 1 || game->nb_exits < 1 || game->nb_players < 1
		|| game->frodo > 1 || game->gollum > 1 || game->nb_orc > 1)
		return (-1);
	if (check_line_len(game) == -1)
		return (-1);
	return (0);
}
