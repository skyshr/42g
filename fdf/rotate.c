/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:17:53 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/30 01:17:53 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_y(t_line *line, double angle);
static void	rotate_z(t_line *line, double angle);

void	rotate(t_cam *cam, t_line *line)
{
	rotate_x(line, cam->alpha);
	rotate_y(line, cam->beta);
	rotate_z(line, cam->gamma);
}

void	rotate_x(t_line *line, double angle)
{
	t_point	start;
	t_point	end;

	start.y = line->start.y * cos(angle) - line->start.z * sin(angle);
	start.z = line->start.y * sin(angle) + line->start.z * cos(angle);
	line->start.y = start.y;
	line->start.z = start.z;
	end.y = line->end.y * cos(angle) - line->end.z * sin(angle);
	end.z = line->end.y * sin(angle) + line->end.z * cos(angle);
	line->end.y = end.y;
	line->end.z = end.z;
}

void	rotate_y(t_line *line, double angle)
{
	t_point	start;
	t_point	end;

	start.x = line->start.x * cos(angle) + line->start.z * sin(angle);
	start.z = -line->start.x * sin(angle) + line->start.z * cos(angle);
	line->start.x = start.x;
	line->start.z = start.z;
	end.x = line->end.x * cos(angle) + line->end.z * sin(angle);
	end.z = -line->end.x * sin(angle) + line->end.z * cos(angle);
	line->end.x = end.x;
	line->end.z = end.z;
}

void	rotate_z(t_line *line, double angle)
{
	t_point	start;
	t_point	end;

	start.x = line->start.x * cos(angle) - line->start.y * sin(angle);
	start.y = line->start.x * sin(angle) + line->start.y * cos(angle);
	line->start.x = start.x;
	line->start.y = start.y;
	end.x = line->end.x * cos(angle) - line->end.y * sin(angle);
	end.y = line->end.x * sin(angle) + line->end.y * cos(angle);
	line->end.x = end.x;
	line->end.y = end.y;
}
