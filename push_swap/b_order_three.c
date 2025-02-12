/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_order_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:26:42 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:26:43 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_two(t_list **lst1, t_list **lst2)
{
	swap(lst1, lst2, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_three(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->order > (*lst1)->next->order)
	{
		if ((*lst1)->next->next->order > (*lst1)->order)
			b_three_213(lst1, lst2);
		else if ((*lst1)->order > (*lst1)->next->next->order)
			b_three_312(lst1, lst2);
	}
	else
	{
		if ((*lst1)->order > (*lst1)->next->next->order)
			b_three_231(lst1, lst2);
		else if ((*lst1)->next->order > (*lst1)->next->next->order)
			b_three_132(lst1, lst2);
		else
			b_three_123(lst1, lst2);
	}
}

void	b_three_213(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	swap(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst2, lst1, 0);
	push(lst1, lst2, 1);
}
