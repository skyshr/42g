/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_order_four1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:17:15 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:17:16 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_four(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->order < (*lst1)->next->order)
	{
		if ((*lst1)->next->order < (*lst1)->next->next->order)
			b_four_first(lst1, lst2);
		else if ((*lst1)->order > (*lst1)->next->next->order)
			b_four_second(lst1, lst2);
		else
			b_four_third(lst1, lst2);
	}
	else
	{
		if ((*lst1)->next->order > (*lst1)->next->next->order)
			b_four_fourth(lst1, lst2);
		else if ((*lst1)->order < (*lst1)->next->next->order)
			b_four_fifth(lst1, lst2);
		else
			b_four_sixth(lst1, lst2);
	}
}

void	b_four_first(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		b_four_1234(lst1, lst2);
	else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		b_four_1243(lst1, lst2);
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		b_four_1342(lst1, lst2);
	else
		b_four_2341(lst1, lst2);
}

void	b_four_second(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		b_four_2314(lst1, lst2);
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		b_four_2413(lst1, lst2);
	else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		b_four_3412(lst1, lst2);
	else
		b_four_3421(lst1, lst2);
}

void	b_four_third(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		b_four_1324(lst1, lst2);
	else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		b_four_1423(lst1, lst2);
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		b_four_1432(lst1, lst2);
	else
		b_four_2431(lst1, lst2);
}
