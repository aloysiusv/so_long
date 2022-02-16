/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_map_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:34:22 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/16 18:11:02 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	print_map(char **map, size_t width, size_t height)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
