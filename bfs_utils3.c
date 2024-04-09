/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:45:26 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/09 00:45:28 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_lookup *dc, int memo[400][4])
{
	if (dc->second && !is_visited(memo, dc->find, dc->pa, dc->rems))
	{
		memo[dc->find][0] = dc->pa;
		memo[dc->find][1] = dc->rems;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 0;
	}
}

void	pb(t_lookup *dc, int memo[400][4])
{
	int	next;

	next = dc->dist + 1;
	if (!is_visited(memo, dc->find, dc->remf, dc->pb))
	{
		memo[dc->find][0] = dc->remf;
		memo[dc->find][1] = dc->pb;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 1;
	}
}

void	sa(t_lookup *dc, int memo[400][4])
{
	if (!is_visited(memo, dc->find, dc->sa, dc->second))
	{
		memo[dc->find][0] = dc->sa;
		memo[dc->find][1] = dc->second;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 2;
	}
}

void	sb(t_lookup *dc, int memo[400][4])
{
	if (dc->second > 10 && !is_visited(memo, dc->find, dc->first, dc->sb))
	{
		memo[dc->find][0] = dc->first;
		memo[dc->find][1] = dc->sb;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 3;
	}
}

void	ss(t_lookup *dc, int memo[400][4])
{
	if (dc->second > 10 && !is_visited(memo, dc->find, dc->sa, dc->sb))
	{
		memo[dc->find][0] = dc->sa;
		memo[dc->find][1] = dc->sb;
		memo[dc->find][2] = dc->dist + 1;
		memo[dc->find++][3] = memo[dc->cur][3] * 11 + 4;
	}
}
