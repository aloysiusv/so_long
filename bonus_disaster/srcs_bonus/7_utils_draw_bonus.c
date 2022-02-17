/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_utils_draw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:25:15 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/17 19:57:18 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

static void	put_pixels(t_img *mlx_img, int x, int y, int colour)
{
	char *pixel;

	pixel = mlx_img->data + (x * (mlx_img->bpp / 8) + y * mlx_img->size_line);
	*(int*)pixel = colour;
}

static int get_pixel(t_img *texture, int x, int y)
{	
	char	*pixel;
	
	pixel = texture->data + (x * (texture->bpp / 8) + y * texture->size_line);
	return (*(int*)pixel);
}

void	draw_canvas(t_img *mlx_img, int x, int y, int size, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixels(mlx_img, x + j, y + i, colour);
			j++;
		}
		i++;
	}		
}

void	draw_texture(t_img *mlx_img, int x, int y, t_img *texture)
{
	int	i;
	int	j;

	i = 0;
	while (i < 40)
	{
		j = 0;
		while (j < 40)
		{
			put_pixels(mlx_img, x + j, y + i, get_pixel(texture, j, i));
			j++;
		}
		i++;
	}	
}
