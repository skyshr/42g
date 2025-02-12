/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:47:23 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/09 00:47:28 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_lookup *dc, int memo[400][4])
{
	if (dc->second > 10 && !is_visited(memo, dc->find, dc->rra, dc->rrb))
	{
		memo[dc->find][0] = dc->rra;
		memo[dc->find][1] = dc->rrb;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 10;
	}
}

int	is_visited(int memo[400][4], int find, int to_find1, int to_find2)
{
	int	i;

	i = 0;
	if (to_find2 >= 100)
		return (1);
	while (i < find)
	{
		if (memo[i][0] == to_find1 && memo[i][1] == to_find2)
			return (1);
		i++;
	}
	return (0);
}
