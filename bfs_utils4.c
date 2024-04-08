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

void	ra(t_lookup *dc, int visited[400][2], int memo[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (!is_visited(visited, dc->find, dc->ra, dc->second))
	{
		visited[dc->find][0] = dc->ra;
		visited[dc->find++][1] = dc->second;
		memo[next][idx[next]][0] = dc->ra;
		memo[next][idx[next]][1] = dc->second;
		memo[next][idx[next]][2] = memo[dc->dist][dc->cur][2] * 11 + 5;
		idx[next]++;
	}
}

void	rb(t_lookup *dc, int visited[400][2], int memo[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (dc->second > 10 && !is_visited(visited, dc->find, dc->first, dc->rb))
	{
		visited[dc->find][0] = dc->first;
		visited[dc->find++][1] = dc->rb;
		memo[next][idx[next]][0] = dc->first;
		memo[next][idx[next]][1] = dc->rb;
		memo[next][idx[next]][2] = memo[dc->dist][dc->cur][2] * 11 + 6;
		idx[next]++;
	}
}

void	rr(t_lookup *dc, int visited[400][2], int memo[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (dc->second > 10 && !is_visited(visited, dc->find, dc->ra, dc->rb))
	{
		visited[dc->find][0] = dc->ra;
		visited[dc->find++][1] = dc->rb;
		memo[next][idx[next]][0] = dc->ra;
		memo[next][idx[next]][1] = dc->rb;
		memo[next][idx[next]][2] = memo[dc->dist][dc->cur][2] * 11 + 7;
		idx[next]++;
	}
}

void	rra(t_lookup *dc, int v[400][2], int m[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (!is_visited(v, dc->find, dc->rra, dc->second))
	{
		v[dc->find][0] = dc->rra;
		v[dc->find++][1] = dc->second;
		m[next][idx[next]][0] = dc->rra;
		m[next][idx[next]][1] = dc->second;
		m[next][idx[next]][2] = m[dc->dist][dc->cur][2] * 11 + 8;
		idx[next]++;
	}
}

void	rrb(t_lookup *dc, int v[400][2], int m[10][400][3], int idx[10])
{
	int	next;

	next = dc->dist + 1;
	if (dc->second > 10 && !is_visited(v, dc->find, dc->first, dc->rrb))
	{
		v[dc->find][0] = dc->first;
		v[dc->find++][1] = dc->rrb;
		m[next][idx[next]][0] = dc->first;
		m[next][idx[next]][1] = dc->rrb;
		m[next][idx[next]][2] = m[dc->dist][dc->cur][2] * 11 + 9;
		idx[next]++;
	}
}
