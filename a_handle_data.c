/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_handle_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:09:59 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:10:00 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_handle_unsorted_four(t_list **lst1, t_list **lst2, int size)
{
	if (size == 2)
		swap(lst1, 0);
	else if (size == 3)
		a_three(lst1, lst2);
	else
		a_four(lst1, lst2);
}

void	a_divide_top_mid_bot(t_list **lst1, t_list **lst2, int left, int right)
{
	int	size;
	int	pivot;
	int	spivot;

	size = right - left;
	pivot = left + size / 3 + (size % 3 == 1);
	spivot = pivot + size / 3 + (size % 3 == 2);
	while (size--)
	{
		if ((*lst1)->order <= pivot)
			push(lst1, lst2, 0);
		else if ((*lst1)->order <= spivot)
			push_rotate(lst1, lst2, 0);
		else
			rotate(lst1, 0);
	}
	size = right - spivot;
	while (size--)
		reverse_rotate_both(lst1, lst2, 2);
}

void	a_to_b(t_list **lst1, t_list **lst2, int left, int right)
{
	int	size;
	int	pivot;
	int	spivot;

	size = right - left;
	pivot = left + size / 3 + (size % 3 == 1);
	spivot = pivot + size / 3 + (size % 3 == 2);
	if (is_ordered(*lst1, 0, size))
		return ;
	if (size <= 4)
	{
		a_handle_unsorted_four(lst1, lst2, size);
		return ;
	}
	a_divide_top_mid_bot(lst1, lst2, left, right);
	a_to_b(lst1, lst2, spivot, right);
	b_to_a(lst2, lst1, pivot, spivot);
	b_to_a(lst2, lst1, left, pivot);
}
