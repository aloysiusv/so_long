/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_map_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:41:55 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/25 01:20:57 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	check_line_len(t_game *game)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < game->height)
	{
		len = ft_strlen(game->map[i]);
		if (len != game->width)
			return (-1);
		i++;
	}
	return (0);
}

static int	borders_or_chars_and_keep_count(t_game *game, int i, int j)
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
		game->nb_player++;
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
	if (game->nb_swords < 1 || game->nb_exits < 1 || game->nb_player != 1)
		return (-1);
	if (check_line_len(game) == -1)
		return (-1);
	return (0);
}

static int	check_extension(char *ext, char *filename)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(filename) < 5)
		return (-1);
	i = ft_strlen(filename) - 4;
	j = 0;
	while (ext[j])
	{
		if (ext[j] != filename[i])
			return (-1);
		i++;
		j++;
	}
	return (0);
}

int	is_map_valid(t_game *game, char *filename)
{
	if (check_extension(".ber", filename) == -1)
		return (-1);
	if (get_map(game, filename) == -1)
		return (-1);
	if (check_map(game) == -1)
		return (-1);
	return (0);
}
