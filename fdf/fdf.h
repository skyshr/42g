/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:19:46 by ksuh              #+#    #+#             */
/*   Updated: 2024/08/30 16:55:47 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include "math.h"
# include "libft/libft.h"

# define WINDOW_WIDTH	1500
# define WINDOW_HEIGHT	1000
# define WINDOW_TITLE	"FDF"
# define MAX_PIXEL		1500000
# define HEX_BASE 		"0123456789abcdef"

# define WH 0xffffff
# define BK 0x0

# define ANG_1		0.01745329
# define ANG_30		0.52359877
# define ANG_45		0.78539816

# define ISOMETRIC		0
# define PERSPECTIVE	1

# define KEY_ESC	65307
# define KEY_PLUS	61
# define KEY_MINUS	45
# define KEY_R		114
# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100
# define KEY_Q		113
# define KEY_E		101
# define KEY_Z		122
# define KEY_X		120
# define KEY_I		105
# define KEY_P		112
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	float	transform_z;
}	t_line;

typedef struct s_cam
{
	int		projection;
	int		move_x;
	int		move_y;
	int		scale;
	double	z_scale;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

typedef struct s_image
{
	void	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*buffer;
	t_line	*line;
}	t_image;

typedef struct s_map
{
	t_point	**coords;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
	int		error;
}	t_map;

typedef struct s_fdf
{
	t_map	*map;
	t_image	*img;
	t_cam	*cam;
	int		win_x;
	int		win_y;
	void	*mlx;
	void	*win;
}	t_fdf;

t_fdf	*init_fdf(char *filename);
t_map	*init_map(void);
t_image	*init_img(void *mlx);
t_cam	*init_cam(t_map *map);
t_point	**init_coords(int width, int height);
t_line	*init_line(t_point start, t_point end, t_fdf *fdf);
t_map	*read_map(t_fdf *fdf, char *filename);
int		get_split_length(char *str, char c);
void	split_free(char **split);
int		is_valid(char **split, int index, int cmp, int error);
void	free_coords(t_point **coords, int x);
void	init_point(t_point **coords, int x, int y);
void	close_map(t_fdf *fdf, t_map *map, int fd, int error_num);
void	close_map_mlx(t_fdf *fdf, int error_num);
void	close_all(t_fdf *fdf, int error_num);
int		error(int error_num);
int		key_handle(int keycode, t_fdf *fdf);
float	get_scale(t_map *map);
void	fdf_reset(t_fdf *fdf);
void	draw(t_fdf *fdf);
void	clear_image(t_image *img);
void	pixel_to_image(t_image *img, float x, float y, int color);
void	rotate(t_cam *cam, t_line *line);
void	rotate_x(t_line *line, double angle);
void	scale(t_line *line, int scale);
void	project(t_cam *cam, t_line *line);
void	transform(t_cam *cam, t_line *line);
void	bresenhem(t_fdf *fdf, t_point start, t_point end);
int		main(int argc, char **argv);

#endif