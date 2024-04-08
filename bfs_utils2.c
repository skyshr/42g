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

int	is_visited(int visited[1800][2], int find, int to_find1, int to_find2)
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

void	bfs(t_list **lst1, t_list **lst2, int size)
{
	unsigned long long	memo[10][480][3];
	int					idx[10];
	int					visited[1800][2];
	unsigned long long	target;
	int					find;
	int					dist;

	if (!(*lst1) || size >= 6)
		return ;
	target = get_target(lst1);
	find = 0;
	ft_bzero(idx, sizeof(int) * 10);
	idx[0]++;
	memo[0][0][0] = get_start(size);
	memo[0][0][2] = 0;
	visited[find][0] = memo[0][0][0];
	visited[find][1] = 0;
	dist = 0;
	while (1)
	{
		int previdx = 0;
		while (previdx < idx[dist])
		{
			if (memo[dist][previdx][0] == target)
			{
				print_answer(lst1, lst2, dist, memo[dist][previdx][2]);
				return ;
			}
			if (dist == 0)
			{
				long long c = memo[dist][previdx][0];
				long long d = find_tens(c);
				long long e = find_tens(memo[dist][previdx][1]);
				long long f = c / d;
				long long g = c % d;
				long long h = memo[dist][previdx][1];
				long long pb = h + f * e;
				long long sa = (g / (d / 10)) * d + f * (d / 10) + g % (d / 10);
				long long ra = 10 * g + f;
				long long rra = (c % 10) * d + (c / 10);
				// pb
				visited[find][0] = g;
				visited[find++][1] = pb;
				memo[dist + 1][idx[dist + 1]][0] = g;
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1] + f * e;
				memo[dist + 1][idx[dist + 1]][2] = memo[dist][idx[dist]][2] * 11 + 1;
				idx[dist + 1]++;
				// sa
				visited[find][0] = sa;
				visited[find++][1] = h;
				memo[dist + 1][idx[dist + 1]][0] = sa;
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1];
				memo[dist + 1][idx[dist + 1]][2] = memo[dist][idx[dist]][2] * 11 + 2;
				idx[dist + 1]++;
				// ra
				visited[find][0] = ra;
				visited[find++][1] = h;
				memo[dist + 1][idx[dist + 1]][0] = g * 10 + f;
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1];
				memo[dist + 1][idx[dist + 1]][2] = memo[dist][idx[dist]][2] * 11 + 5;
				idx[dist + 1]++;
				// rra
				visited[find][0] = rra;
				visited[find++][1] = h;
				memo[dist + 1][idx[dist + 1]][0] = rra;
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1];
				memo[dist + 1][idx[dist + 1]][2] = memo[dist][idx[dist]][2] * 11 + 8;
				idx[dist + 1]++;
			}
			else
			{
				unsigned long long c = memo[dist][previdx][0];
				unsigned long long h = memo[dist][previdx][1];
				unsigned long long d = find_tens(c);
				unsigned long long e = find_tens(h);
				unsigned long long f = c / d;
				unsigned long long g = c % d;
				unsigned long long i = h / e;
				unsigned long long j = h % e;
				unsigned long long pa; 
				unsigned long long pb;
				unsigned long long sa;
				unsigned long long sb;
				unsigned long long ra = 10 * g + f;
				unsigned long long rb = 10 * j + i;
				unsigned long long rra;
				unsigned long long rrb;
				if (h)
					pa = 10 * d * i + c;
				else
					pa = c;
				if (h)
					pb = 10 * e * f + h;
				else
					pb = f;
				if (c > 10)
					sa = (g / (d / 10)) * d + f * (d / 10) + g % (d / 10);
				else 
					sa = c;
				if (h > 10)
					sb = (j / (e / 10)) * e + i * (e / 10) + j % (e / 10);
				else
					sb = h;
				if (c)
					rra = (c % 10) * d + (c / 10);
				else
					rra = c;
				if (h)
					rrb = (h % 10) * e + (h / 10);
				else
					rrb = h;
				if (!is_visited(visited, find, pa, j))
				{
					if (h)
					{
						visited[find][0] = pa;
						visited[find++][1] = j;
						memo[dist + 1][idx[dist + 1]][0] = pa;
						memo[dist + 1][idx[dist + 1]][1] = j;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 0;
						idx[dist + 1]++;
					}
				}
				// pb
				if (!is_visited(visited, find, g, pb))
				{
					if (c)
					{
						visited[find][0] = g;
						visited[find++][1] = pb;
						memo[dist + 1][idx[dist + 1]][0] = g;
						memo[dist + 1][idx[dist + 1]][1] = pb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 1;
						idx[dist + 1]++;
					}
				}
				// sa
				if (!is_visited(visited, find, sa, h))
				{
					if (c > 10)
					{
						visited[find][0] = sa;
						visited[find++][1] = h;
						memo[dist + 1][idx[dist + 1]][0] = sa;
						memo[dist + 1][idx[dist + 1]][1] = h;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 2;
						idx[dist + 1]++;
					}
				}
				// sb
				if (!is_visited(visited, find, c, sb))
				{
					if (h > 10)
					{
						visited[find][0] = c;
						visited[find++][1] = sb;
						memo[dist + 1][idx[dist + 1]][0] = c;
						memo[dist + 1][idx[dist + 1]][1] = sb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 3;
						idx[dist + 1]++;
					}
				}
				// ss
				if (!is_visited(visited, find, sa, sb))
				{
					if (c > 10 && h > 10)
					{
						visited[find][0] = sa;
						visited[find++][1] = sb;
						memo[dist + 1][idx[dist + 1]][0] = sa;
						memo[dist + 1][idx[dist + 1]][1] = sb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 4;
						idx[dist + 1]++;
					}
				}
				// ra
				if (!is_visited(visited, find, ra, h))
				{
					if (c > 10)
					{
						visited[find][0] = ra;
						visited[find++][1] = h;
						memo[dist + 1][idx[dist + 1]][0] = ra;
						memo[dist + 1][idx[dist + 1]][1] = h;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 5;
						idx[dist + 1]++;
					}
				}
				// rb
				if (!is_visited(visited, find, c, rb))
				{
					if (h > 10)
					{
						visited[find][0] = c;
						visited[find++][1] = rb;
						memo[dist + 1][idx[dist + 1]][0] = c;
						memo[dist + 1][idx[dist + 1]][1] = rb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 6;
						idx[dist + 1]++;
					}
				}
				// rr
				if (!is_visited(visited, find, ra, rb))
				{
					if (c > 10 && h > 10)
					{
						visited[find][0] = ra;
						visited[find++][1] = rb;
						memo[dist + 1][idx[dist + 1]][0] = ra;
						memo[dist + 1][idx[dist + 1]][1] = rb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 7;
						idx[dist + 1]++;
					}
				}
				// rra
				if (!is_visited(visited, find, rra, h))
				{
					if (c > 10)
					{
						visited[find][0] = rra;
						visited[find++][1] = h;
						memo[dist + 1][idx[dist + 1]][0] = rra;
						memo[dist + 1][idx[dist + 1]][1] = h;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 8;
						idx[dist + 1]++;
					}
				}
				// rrb
				if (!is_visited(visited, find, c, rrb))
				{
					if (h > 10)
					{
						visited[find][0] = c;
						visited[find++][1] = rrb;
						memo[dist + 1][idx[dist + 1]][0] = c;
						memo[dist + 1][idx[dist + 1]][1] = rrb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 9;
						idx[dist + 1]++;
					}
				}
				// rrr
				if (!is_visited(visited, find, rra, rrb))
				{
					if (c > 10 && h > 10)
					{
						visited[find][0] = rra;
						visited[find++][1] = rrb;
						memo[dist + 1][idx[dist + 1]][0] = rra;
						memo[dist + 1][idx[dist + 1]][1] = rrb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 10;
						idx[dist + 1]++;
					}
				}
			}
			previdx++;
		}
		dist++;
	}
}