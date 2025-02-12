/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:11:21 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/29 22:11:22 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_map(t_fdf *fdf, t_map *map, int fd, int error_num)
{
	free_coords(map->coords, map->max_x);
	free(map);
	free(fdf);
	close(fd);
	error(error_num);
}

void	close_map_mlx(t_fdf *fdf, int error_num)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free_coords(fdf->map->coords, fdf->map->max_x);
	free(fdf->map);
	free(fdf->mlx);
	free(fdf);
	error(error_num);
}

void	close_all(t_fdf *fdf, int error_num)
{
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free_coords(fdf->map->coords, fdf->map->max_x);
	free(fdf->map);
	free(fdf->img);
	free(fdf->cam);
	free(fdf->mlx);
	fdf->mlx = NULL;
	free(fdf);
	error(error_num);
}
