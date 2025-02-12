/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:32:27 by ksuh              #+#    #+#             */
/*   Updated: 2024/08/30 16:55:26 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	absolute(float x);

void	bresenhem(t_fdf *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max_step;
	int		i;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_step = (int)ft_max(absolute(x_step), absolute(y_step));
	x_step /= max_step;
	y_step /= max_step;
	i = 0;
	while (i++ < max_step)
	{
		if (start.x > 0 && start.x < WINDOW_WIDTH && \
			start.y > 0 && start.y < WINDOW_HEIGHT)
			pixel_to_image(fdf->img, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
}

int	absolute(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}
