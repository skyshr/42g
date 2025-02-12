/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:13:00 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/29 22:13:03 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(char *filename)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		error(3);
	fdf->map = read_map(fdf, filename);
	if (!fdf->map)
	{
		free(fdf);
		error(4);
	}
	fdf->mlx = mlx_init();
	fdf->win_x = WINDOW_WIDTH;
	fdf->win_y = WINDOW_HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, WINDOW_TITLE);
	fdf->img = init_img(fdf->mlx);
	if (!fdf->img)
		close_map_mlx(fdf, 5);
	fdf->cam = init_cam(fdf->map);
	if (!fdf->cam)
		close_all(fdf, 6);
	return (fdf);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->coords = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->error = 0;
	return (map);
}

t_image	*init_img(void *mlx)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->buffer = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
				&img->size_line, &img->endian);
	img->line = NULL;
	return (img);
}

t_cam	*init_cam(t_map *map)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->move_x = WINDOW_WIDTH / 2;
	cam->move_y = WINDOW_HEIGHT / 2;
	cam->scale = (int)get_scale(map);
	cam->z_scale = 1;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	return (cam);
}

t_point	**init_coords(int width, int height)
{
	t_point	**coord;
	int		x;
	int		y;

	if (!width || !height)
		return (NULL);
	coord = malloc(sizeof(t_point *) * width);
	if (!coord)
		return (NULL);
	x = 0;
	while (x < width)
	{
		coord[x] = malloc(sizeof(t_point) * height);
		if (!coord[x])
		{
			free_coords(coord, x);
			return (NULL);
		}
		y = -1;
		while (++y < height)
			init_point(coord, x, y);
		x++;
	}
	return (coord);
}
