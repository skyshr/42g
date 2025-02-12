/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:12:51 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/29 22:12:51 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_split_length(char *str, char c)
{
	int	len;

	len = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			while (*str && *str != c)
				str++;
			len++;
		}
	}
	return (len);
}

void	split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	is_valid(char **split, int index, int cmp, int error)
{
	split_free(split);
	if (index != cmp || error)
		return (0);
	return (1);
}

void	free_coords(t_point **coords, int x)
{
	int	i;

	i = 0;
	while (i < x)
		free(coords[i++]);
	free(coords);
}

void	init_point(t_point **coords, int i, int j)
{
	coords[i][j].x = 0;
	coords[i][j].y = 0;
	coords[i][j].z = 0;
	coords[i][j].color = -1;
}
