/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_handle_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:28:58 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:28:59 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_handle_unsorted_four(t_list **lst1, t_list **lst2, int size)
{
	if (size == 2)
	{
		swap(lst1, 1);
		push(lst1, lst2, 1);
		push(lst1, lst2, 1);
		return ;
	}
	else if (size == 3)
		b_three(lst1, lst2);
	else
		b_four(lst1, lst2);
}

void	b_divide_top_mid_bot(t_list **lst1, t_list **lst2, int left, int right)
{
	int	size;
	int	pivot;
	int	spivot;

	size = right - left;
	pivot = left + size / 3 + (size % 3 == 2);
	spivot = pivot + size / 3 + (size % 3 == 2);
	while (size--)
	{
		if ((*lst1)->order <= pivot)
			rotate(lst1, 1);
		else if ((*lst1)->order <= spivot)
			push_rotate(lst1, lst2, 1);
		else
			push(lst1, lst2, 1);
	}
}

void	b_to_a(t_list **lst1, t_list **lst2, int left, int right)
{
	int	pivot;
	int	spivot;
	int	size;

	size = right - left;
	if (is_ordered(*lst1, 1, size))
	{
		while (size--)
			push(lst1, lst2, 1);
		return ;
	}
	if (size <= 4)
	{
		b_handle_unsorted_four(lst1, lst2, size);
		return ;
	}
	b_divide_top_mid_bot(lst1, lst2, left, right);
	pivot = left + size / 3 + (size % 3 == 2);
	spivot = pivot + size / 3 + (size % 3 == 2);
	a_to_b(lst2, lst1, spivot, right);
	size = pivot - left;
	while (size--)
		reverse_rotate_both(lst1, lst2, 2);
	a_to_b(lst2, lst1, pivot, spivot);
	b_to_a(lst1, lst2, left, pivot);
}
