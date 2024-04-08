/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:22:31 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 22:22:32 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_list **lst)
{
	t_list	*cur;
	int		target;

	cur = *lst;
	target = 0;
	while (cur)
	{
		target = target * 10 + cur->order;
		cur = cur->next;
	}
	return (target);
}

unsigned long long	find_tens(unsigned long long num)
{
	unsigned long long	res;

	res = 1;
	while (num / 10)
	{
		num /= 10;
		res *= 10;
	}
	return (res);
}

int	get_start(int size)
{
	int	res;
	int	i;

	res = 1;
	i = 2;
	while (i <= size)
		res = res * 10 + i++;
	return (res);
}

void	do_operation(t_list **lst1, t_list **lst2, int n)
{
	if (n == 0)
		push(lst1, &lst2, 0);
	else if (n == 1)
		push(&lst2, lst1, 1);
	else if (n == 2)
		swap(lst1, lst2, 0);
	else if (n == 3)
		swap(&lst2, lst1, 1);
	else if (n == 4)
		swap_both(lst1, &lst2, 2);
	else if (n == 5)
		reverse_rotate(lst1, lst2, 0);
	else if (n == 6)
		reverse_rotate(&lst2, lst1, 1);
	else if (n == 7)
		reverse_rotate_both(lst1, &lst2, 2);
	else if (n == 8)
		rotate(lst1, lst2, 0);
	else if (n == 9)
		rotate(&lst2, lst1, 1);
	else
		rotate_both(lst1, &lst2, 2);
}

void	print_answer(t_list **l1, t_list **l2, int d, unsigned long long n)
{
	int		m;
	int		tmp;

	tmp = d;
	while (d--)
	{
		m = n % 11;
		do_operation(&l1, &l2, m);
		n /= 11;
	}
	ft_lstclear(l1);
	ft_lstclear(&l2);
}
