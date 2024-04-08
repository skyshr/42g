/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:20:18 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 22:20:19 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_visited(int visited[400][2], int find, int to_find1, int to_find2)
{
	int	i;

	i = 0;
	if (to_find2 >= 100)
		return (1);
	while (i < find)
	{
		if (visited[i][0] == to_find1 && visited[i][1] == to_find2)
			return (1);
		i++;
	}
	return (0);
}

void	setup(t_list *lst, t_lookup *dc, int m[10][400][3], int v[400][2])
{
	int	size;

	size = ft_lstsize(lst);
	dc->target = get_target(lst);
	dc->find = 1;
	dc->dist = 0;
	m[0][0][0] = get_start(size);
	m[0][0][1] = 0;
	m[0][0][2] = 0;
	v[0][0] = m[0][0][0];
	v[0][1] = 0;
}

void	reset(t_lookup *dc, int memo[10][400][3])
{
	dc->first = memo[dc->dist][dc->cur][0];
	dc->second = memo[dc->dist][dc->cur][1];
	dc->third = memo[dc->dist][dc->cur][2];
	dc->tenf = find_tens(dc->first);
	dc->tens = find_tens(dc->second);
	dc->quof = dc->first / dc->tenf;
	dc->quos = dc->second / dc->tens;
	dc->remf = dc->first % dc->tenf;
	dc->rems = dc->second % dc->tens;
	dc->pa = dc->first + 10 * dc->tens * dc->quos;
	dc->pb = dc->second + 10 * dc->tenf * dc->quof;
	dc->sa = dc->first;
	if (dc->first > 10)
		dc->sa = (dc->remf / (dc->tenf / 10)) * dc->tenf + dc->quof * \
				(dc->tenf / 10) + dc->remf % (dc->tenf / 10);
	else
		dc->sa = dc->first;
	if (dc->second > 10)
		dc->sb = (dc->rems / (dc->tens / 10)) * dc->tens + dc->quos * \
				(dc->tens / 10) + dc->rems % (dc->tens / 10);
	else
		dc->sb = dc->second;
	dc->rra = (dc->first % 10) * dc->tenf + (dc->first / 10);
	dc->rrb = (dc->second % 10) * dc->tens + (dc->second / 10);
}

void	find_path(t_lookup *dc, int v[400][2], int m[10][400][3], int idx[10])
{
	pa(dc, v, m, idx);
	pb(dc, v, m, idx);
	sa(dc, v, m, idx);
	sb(dc, v, m, idx);
	ss(dc, v, m, idx);
	ra(dc, v, m, idx);
	rb(dc, v, m, idx);
	rr(dc, v, m, idx);
	rra(dc, v, m, idx);
	rrb(dc, v, m, idx);
	rrr(dc, v, m, idx);
}

void	bfs(t_list **lst1, t_list **lst2, int size)
{
	t_lookup	dc;
	int			memo[10][400][3];
	int			idx[10];
	int			visited[400][2];

	setup(*lst1, &dc, memo, visited);
	ft_bzero(idx, sizeof(int) * 10);
	idx[0] = 1;
	while (1)
	{
		dc.cur = 0;
		while (dc.cur < idx[dc.dist])
		{
			if (memo[dc.dist][dc.cur][0] == dc.target)
				print_answer(lst1, lst2, dc.dist, memo[dc.dist][dc.cur][2]);
			reset(&dc, memo);
			find_path(&dc, visited, memo, idx);
			dc.cur++;
		}
		dc.dist++;
	}
}

// pa 0 pb 1 sa 2 sb 3 ss 4 ra 5 rb 6 rr 7 rra 8 rrb 9 rrr 10