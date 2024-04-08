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

void	pa(t_lookup *dc, int visited[400][2], int memo[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (dc->second && !is_visited(visited, dc->find, dc->pa, dc->rems))
	{
		visited[dc->find][0] = dc->pa;
		visited[dc->find++][1] = dc->rems;
		memo[next][idx[next]][0] = dc->pa;
		memo[next][idx[next]][1] = dc->rems;
		memo[next][idx[next]][2] = memo[dc->dist][dc->cur][2] * 11 + 0;
		idx[next]++;
	}
}

void	pb(t_lookup *dc, int visited[400][2], int memo[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (!is_visited(visited, dc->find, dc->remf, dc->pb))
	{
		visited[dc->find][0] = dc->remf;
		visited[dc->find++][1] = dc->pb;
		memo[next][idx[next]][0] = dc->remf;
		memo[next][idx[next]][1] = dc->pb;
		memo[next][idx[next]][2] = memo[dc->dist][dc->cur][2] * 11 + 1;
		idx[next]++;
	}
}

void	sa(t_lookup *dc, int visited[400][2], int memo[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (!is_visited(visited, dc->find, dc->sa, dc->second))
	{
		visited[dc->find][0] = dc->sa;
		visited[dc->find++][1] = dc->second;
		memo[next][idx[next]][0] = dc->sa;
		memo[next][idx[next]][1] = dc->second;
		memo[next][idx[next]][2] = memo[dc->dist][dc->cur][2] * 11 + 2;
		idx[next]++;
	}
}

void	sb(t_lookup *dc, int visited[400][2], int memo[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (dc->second > 10 && !is_visited(visited, dc->find, dc->first, dc->sb))
	{
		visited[dc->find][0] = dc->first;
		visited[dc->find++][1] = dc->sb;
		memo[next][idx[next]][0] = dc->first;
		memo[next][idx[next]][1] = dc->sb;
		memo[next][idx[next]][2] = memo[dc->dist][dc->cur][2] * 11 + 3;
		idx[next]++;
	}
}

void	ss(t_lookup *dc, int visited[400][2], int memo[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (dc->second > 10 && !is_visited(visited, dc->find, dc->sa, dc->sb))
	{
		visited[dc->find][0] = dc->sa;
		visited[dc->find++][1] = dc->sb;
		memo[next][idx[next]][0] = dc->sa;
		memo[next][idx[next]][1] = dc->sb;
		memo[next][idx[next]][2] = memo[dc->dist][dc->cur][2] * 11 + 4;
		idx[next]++;
	}
}
