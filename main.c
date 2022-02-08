/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:42:47 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/08 18:12:26 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(const char *s, int fd)
{
	if (s == 0)
		return ;
	write(fd, s, ft_strlen(s));
}

int     is_ber(const char *ext, const char *file)
{
	size_t	i;
    size_t  j;
    
    i = ft_strlen(file) - 1;
    j = 0;
    while (ext[j])
    {
        if (ext[j] != file[i])
            return(-1);
        i--;
        j++;
    }
	return (0);
}

int check_extension(char *file)
{
    if (ft_strlen(file) > 4 && is_ber("reb.", file) && file[0] != '.')
        return (0);
    else
        return (-1);
}

char **get_valid_map(char *file)
{
    int fd;

    if (is_ber("reb.", file) < 0)
        return (NULL);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);
}

int main(int ac, char **av)
{
    char **map;

    if (ac != 2)
    {
        ft_putstr_fd("Invalid input\n", 2);
        exit(EXIT_FAILURE);
    }
    map = get_valid_map(av[1]);
    if (map == NULL) 
    {
        ft_putstr_fd("Wrong map\n", 2);
        exit(EXIT_FAILURE);
    }
}
