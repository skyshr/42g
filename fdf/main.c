/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:12:07 by ksuh              #+#    #+#             */
/*   Updated: 2024/05/29 21:05:42 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_win(t_fdf *fdf);

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*filename;

	if (argc != 2)
		error(1);
	filename = argv[1];
	fdf = init_fdf(filename);
	draw(fdf);
	mlx_hook(fdf->win, 17, 1L << 0, &close_win, fdf);
	mlx_key_hook(fdf->win, &key_handle, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

int	close_win(t_fdf *fdf)
{
	close_all(fdf, 0);
	return (0);
}
