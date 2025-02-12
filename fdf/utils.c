/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:38:45 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/29 22:38:45 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	min(float x, float y);

float	get_scale(t_map *map)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	scale_x = WINDOW_WIDTH / map->max_x;
	scale_y = WINDOW_HEIGHT / map->max_y;
	scale_factor = min(scale_x, scale_y);
	if (scale_factor < 4)
		return (2);
	return (scale_factor / 2);
}

float	min(float x, float y)
{
	if (x <= y)
		return (x);
	return (y);
}

void	fdf_reset(t_fdf *fdf)
{
	fdf->cam->projection = ISOMETRIC;
	fdf->cam->move_x = WINDOW_WIDTH / 2;
	fdf->cam->move_y = WINDOW_HEIGHT / 2;
	fdf->cam->scale = (int)get_scale(fdf->map);
	fdf->cam->z_scale = 1;
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
}

t_line	*init_line(t_point start, t_point end, t_fdf *fdf)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	line->transform_z = ft_max(ft_max(fdf->map->max_x, fdf->map->max_y), \
						fdf->map->max_z - fdf->map->min_z);
	return (line);
}
