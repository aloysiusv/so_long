/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_map_parse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:42:47 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/24 14:55:31 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes_bonus/so_long_bonus.h"

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
