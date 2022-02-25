/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:36:36 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/25 04:32:55 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes_bonus/so_long_bonus.h"

static int	count_lines(char *filename)
{
	char	*line;
	int		nb_lines;
	int		fd;

	nb_lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		nb_lines++;
		free(line);
	}
	if (line != NULL && *line != 0)
		nb_lines++;
	free(line);
	close(fd);
	return (nb_lines);
}

static void	init_map(t_game *game, int size)
{
	int	i;

	i = 0;
	while (i < size)
		game->map[i++] = NULL;
}

static int	fill_map(t_game *game, int fd, int ret, char *filename)
{
	size_t	i;
	char	*line;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (-1);
	game->width = ft_strlen(line);
	game->map[0] = line;
	i = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &game->map[++i]);
		if (ret == -1)
			return (-1);
	}
	close(fd);
	return (0);
}

int	get_map(t_game *game, char *filename)
{
	int		fd;
	int		ret;

	fd = 0;
	ret = 0;
	game->height = count_lines(filename);
	if (game->height < 3)
		return (-1);
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (game->map == NULL)
		return (-1);
	init_map(game, game->height + 1);
	if (fill_map(game, fd, ret, filename) == -1)
		return (-1);
	return (0);
}
