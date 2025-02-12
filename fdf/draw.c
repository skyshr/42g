/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:51:33 by ksuh              #+#    #+#             */
/*   Updated: 2024/08/30 16:55:38 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_fdf *fdf, t_point start, t_point end);

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	clear_image(fdf->img);
	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
				draw_line(fdf, fdf->map->coords[x][y], \
					fdf->map->coords[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				draw_line(fdf, fdf->map->coords[x][y], \
					fdf->map->coords[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}

void	clear_image(t_image *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			pixel_to_image(img, x, y, BK);
			x++;
		}
		y++;
	}
}

void	pixel_to_image(t_image *img, float x, float y, int color)
{
	int	pixel;

	pixel = ((int)y * img->size_line) + ((int)x * 4);
	img->buffer[pixel + 0] = (color) & 0xff;
	img->buffer[pixel + 1] = (color >> 8) & 0xff;
	img->buffer[pixel + 2] = (color >> 16) & 0xff;
	img->buffer[pixel + 3] = (color >> 24);
}

void	draw_line(t_fdf *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->z_scale;
	end.z *= fdf->cam->z_scale;
	fdf->img->line = init_line(start, end, fdf);
	if (!fdf->img->line)
		close_all(fdf, 7);
	rotate(fdf->cam, fdf->img->line);
	project(fdf->cam, fdf->img->line);
	transform(fdf->cam, fdf->img->line);
	bresenhem(fdf, fdf->img->line->start, fdf->img->line->end);
	free(fdf->img->line);
}
