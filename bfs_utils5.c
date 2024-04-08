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

void	rrr(t_lookup *dc, int v[400][2], int m[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (dc->second > 10 && !is_visited(v, dc->find, dc->rra, dc->rrb))
	{
		v[dc->find][0] = dc->rra;
		v[dc->find++][1] = dc->rrb;
		m[next][idx[next]][0] = dc->rra;
		m[next][idx[next]][1] = dc->rrb;
		m[next][idx[next]][2] = m[dc->dist][dc->cur][2] * 11 + 10;
		idx[next]++;
	}
}
