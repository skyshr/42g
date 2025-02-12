/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:38:34 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/30 10:38:35 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_line *line);
static void	perspective(t_line *line);

void	project(t_cam *cam, t_line *line)
{
	if (cam->projection == ISOMETRIC)
		isometric(line);
	else if (cam->projection == PERSPECTIVE)
		perspective(line);
}

void	isometric(t_line *line)
{
	t_point	point;

	point.x = (line->start.x - line->start.y) * cos(ANG_30);
	point.y = (line->start.x + line->start.y) * sin(ANG_30) \
				- line->start.z;
	line->start.x = point.x;
	line->start.y = point.y;
	point.x = (line->end.x - line->end.y) * cos(ANG_30);
	point.y = (line->end.x + line->end.y) * sin(ANG_30) \
				- line->end.z;
	line->end.x = point.x;
	line->end.y = point.y;
}

void	perspective(t_line *line)
{
	double	z;

	rotate_x(line, 3 * -ANG_45);
	z = line->start.z + line->transform_z;
	line->start.x /= z;
	line->start.y /= -z;
	z = line->end.z + line->transform_z;
	line->end.x /= z;
	line->end.y /= -z;
	scale(line, line->transform_z);
}
