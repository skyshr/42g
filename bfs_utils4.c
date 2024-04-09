/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:46:11 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/09 00:46:12 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_lookup *dc, int memo[400][4])
{
	if (!is_visited(memo, dc->find, dc->ra, dc->second))
	{
		memo[dc->find][0] = dc->ra;
		memo[dc->find][1] = dc->second;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 5;
	}
}

void	rb(t_lookup *dc, int memo[400][4])
{
	if (dc->second > 10 && !is_visited(memo, dc->find, dc->first, dc->rb))
	{
		memo[dc->find][0] = dc->first;
		memo[dc->find][1] = dc->rb;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 6;
	}
}

void	rr(t_lookup *dc, int memo[400][4])
{
	if (dc->second > 10 && !is_visited(memo, dc->find, dc->ra, dc->rb))
	{
		memo[dc->find][0] = dc->ra;
		memo[dc->find][1] = dc->rb;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 7;
	}
}

void	rra(t_lookup *dc, int memo[400][4])
{
	if (!is_visited(memo, dc->find, dc->rra, dc->second))
	{
		memo[dc->find][0] = dc->rra;
		memo[dc->find][1] = dc->second;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 8;
	}
}

void	rrb(t_lookup *dc, int memo[400][4])
{
	if (dc->second > 10 && !is_visited(memo, dc->find, dc->first, dc->rrb))
	{
		memo[dc->find][0] = dc->first;
		memo[dc->find][1] = dc->rrb;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 9;
	}
}
