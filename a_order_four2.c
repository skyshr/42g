/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_order_four2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:52:15 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 15:52:17 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_four_fourth(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->next->next->next->order > (*lst1)->order)
		a_four_3214(lst1, lst2);
	else if ((*lst1)->next->next->next->order < (*lst1)->next->next->order)
		a_four_4321(lst1, lst2);
	else if ((*lst1)->next->next->next->order < (*lst1)->next->order)
		a_four_4312(lst1, lst2);
	else
		a_four_4213(lst1, lst2);
}

void	a_four_fifth(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->next->next->order < (*lst1)->next->next->next->order)
		a_four_2134(lst1);
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		a_four_2143(lst1, lst2);
	else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		a_four_3142(lst1, lst2);
	else
		a_four_3241(lst1, lst2);
}

void	a_four_sixth(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->order < (*lst1)->next->next->next->order)
		a_four_3124(lst1, lst2);
	else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		a_four_4123(lst1, lst2);
	else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		a_four_4132(lst1, lst2);
	else
		a_four_4231(lst1, lst2);
}
