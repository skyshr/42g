/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:52:22 by ksuh              #+#    #+#             */
/*   Updated: 2024/08/30 16:47:55 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_translate(int keycode, t_fdf *fdf);
static void	key_rotate(int keycode, t_fdf *fdf);
static void	key_scale(int keycode, t_fdf *fdf);
static void	key_project(int keycode, t_fdf *fdf);

int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		close_all(fdf, 0);
	else if (keycode == KEY_R)
		fdf_reset(fdf);
	else if (keycode == KEY_UP || keycode == KEY_DOWN || \
				keycode == KEY_LEFT || keycode == KEY_RIGHT)
		key_translate(keycode, fdf);
	else if (keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E || \
				keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		key_rotate(keycode, fdf);
	else if (keycode == KEY_Z || keycode == KEY_X || \
				keycode == KEY_PLUS || keycode == KEY_MINUS)
		key_scale(keycode, fdf);
	else if (keycode == KEY_I || keycode == KEY_P)
		key_project(keycode, fdf);
	draw(fdf);
	return (0);
}

void	key_translate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP)
		fdf->cam->move_y -= 10;
	else if (keycode == KEY_DOWN)
		fdf->cam->move_y += 10;
	else if (keycode == KEY_LEFT)
		fdf->cam->move_x -= 10;
	else if (keycode == KEY_RIGHT)
		fdf->cam->move_x += 10;
}

void	key_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_A)
		fdf->cam->alpha += 5 * ANG_1;
	else if (keycode == KEY_D)
		fdf->cam->alpha += -5 * ANG_1;
	else if (keycode == KEY_W)
		fdf->cam->beta += 5 * ANG_1;
	else if (keycode == KEY_S)
		fdf->cam->beta += -5 * ANG_1;
	else if (keycode == KEY_Q)
		fdf->cam->gamma += 5 * ANG_1;
	else if (keycode == KEY_E)
		fdf->cam->gamma += -5 * ANG_1;
}

void	key_scale(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_Z && fdf->cam->z_scale < 1.5)
		fdf->cam->z_scale += 0.1;
	else if (keycode == KEY_X && fdf->cam->z_scale > -1.5)
		fdf->cam->z_scale -= 0.1;
	else if (keycode == KEY_PLUS && fdf->cam->scale < 62.42)
		fdf->cam->scale += 1.42;
	else if (keycode == KEY_MINUS && fdf->cam->scale > 1)
		fdf->cam->scale -= 1;
}

void	key_project(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_I)
		fdf->cam->projection = ISOMETRIC;
	else if (keycode == KEY_P)
		fdf->cam->projection = PERSPECTIVE;
}
