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

void	setup(t_list *lst, t_lookup *dc, int memo[400][4])
{
	int	size;

	size = ft_lstsize(lst);
	dc->target = get_target(lst);
	dc->find = 1;
	dc->dist = 0;
	dc->cur = 0;
	dc->end = 1;
	memo[0][0] = get_start(size);
	memo[0][1] = 0;
	memo[0][2] = 0;
	memo[0][3] = 0;
}

void	update_ps(t_lookup *dc)
{
	if (dc->second)
		dc->pb = 10 * dc->tens * dc->quof + dc->second;
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
}

void	reset_dc(t_lookup *dc, int memo[400][4])
{
	dc->first = memo[dc->cur][0];
	dc->second = memo[dc->cur][1];
	dc->tenf = find_tens(dc->first);
	dc->tens = find_tens(dc->second);
	dc->quof = dc->first / dc->tenf;
	dc->quos = dc->second / dc->tens;
	dc->remf = dc->first % dc->tenf;
	dc->rems = dc->second % dc->tens;
	dc->pa = dc->first + 10 * dc->tenf * dc->quos;
	dc->pb = dc->quof;
	update_ps(dc);
	dc->ra = 10 * dc->remf + dc->quof;
	dc->rb = 10 * dc->rems + dc->quos;
	dc->rra = (dc->first % 10) * dc->tenf + (dc->first / 10);
	dc->rrb = (dc->second % 10) * dc->tens + (dc->second / 10);
}

void	find_path(t_lookup *dc, int memo[400][4])
{
	pa(dc, memo);
	pb(dc, memo);
	sa(dc, memo);
	sb(dc, memo);
	ss(dc, memo);
	ra(dc, memo);
	rb(dc, memo);
	rr(dc, memo);
	rra(dc, memo);
	rrb(dc, memo);
	rrr(dc, memo);
}

void	bfs(t_list **lst1, t_list **lst2)
{
	t_lookup	dc;
	int			memo[400][4];

	setup(*lst1, &dc, memo);
	while (1)
	{
		while (dc.cur < dc.end)
		{
			if (memo[dc.cur][0] == dc.target)
				print_answer(lst1, lst2, dc.dist, memo[dc.cur][3]);
			reset_dc(&dc, memo);
			find_path(&dc, memo);
			dc.cur++;
		}
		dc.dist++;
		dc.end = dc.find;
	}
}