/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_utils_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:16:31 by lrandria          #+#    #+#             */
/*   Updated: 2022/02/14 17:13:23 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	draw_square(t_img *mlx_img, int x, int y, int size, int colour)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			put_pixels(mlx_img, x + j, y + i, colour);
}

void	draw_texture(t_img *mlx_img, int x, int y, t_img *texture)
{
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 40; j++)
			put_pixels(mlx_img, x + j, y + i, get_pixel(texture, j, i));
}
