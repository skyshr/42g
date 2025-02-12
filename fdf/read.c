/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:12:25 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/29 22:12:26 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_data(t_map *map, char *filename);
static void	get_points(t_fdf *fdf, t_map *map, char *filename);
static void	set_point(t_map *map, int i, int j, char *line);
static void	center_to_origin(t_map *map);

t_map	*read_map(t_fdf *fdf, char *filename)
{
	t_map	*map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(fdf);
		error(2);
	}
	close(fd);
	map = init_map();
	if (!map)
		return (NULL);
	get_data(map, filename);
	map->coords = init_coords(map->max_x, map->max_y);
	if (!map->coords)
	{
		free(map);
		return (NULL);
	}
	get_points(fdf, map, filename);
	center_to_origin(map);
	return (map);
}

void	get_data(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return ;
	map->max_x = get_split_length(line, ' ');
	while (1)
	{
		free(line);
		map->max_y++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (get_split_length(line, ' ') != map->max_x)
		{
			map->max_x = 0;
			free(line);
			break ;
		}
	}
	close(fd);
}

void	get_points(t_fdf *fdf, t_map *map, char *filename)
{
	int		fd;
	int		coord[2];
	char	*line;
	char	**split;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		close_map(fdf, map, fd, 4);
	coord[1] = -1;
	while (++coord[1] < map->max_y)
	{
		line = get_next_line(fd);
		if (!line)
			close_map(fdf, map, fd, 4);
		split = ft_split(line, ' ');
		free(line);
		if (!split)
			close_map(fdf, map, fd, 4);
		coord[0] = -1;
		while (split[++coord[0]] && coord[0] < map->max_x)
			set_point(map, coord[0], coord[1], split[coord[0]]);
		if (!is_valid(split, coord[0], map->max_x, map->error))
			close_map(fdf, map, fd, 4);
	}
	close(fd);
}

void	set_point(t_map *map, int i, int j, char *line)
{
	char	**split;

	if (map->error)
		return ;
	map->coords[i][j].x = (float)i;
	map->coords[i][j].y = (float)j;
	if (ft_strchr(line, ','))
	{
		split = ft_split(line, ',');
		if (!split)
		{
			map->error = 1;
			return ;
		}
		map->coords[i][j].z = (float)ft_atoi(split[0]);
		map->coords[i][j].color = ft_atoi_base(split[1], HEX_BASE);
		split_free(split);
	}
	else
		map->coords[i][j].z = (float)ft_atoi(line);
	map->max_z = ft_max(map->max_z, map->coords[i][j].z);
	map->min_z = ft_min(map->max_z, map->coords[i][j].z);
}

void	center_to_origin(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->max_x)
	{
		j = 0;
		while (j < map->max_y)
		{
			map->coords[i][j].x -= map->max_x / 2;
			map->coords[i][j].y -= map->max_y / 2;
			j++;
		}
		i++;
	}
}
