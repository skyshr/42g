/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_order_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:02:53 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:02:56 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_three(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->order > (*lst1)->next->order)
	{
		if ((*lst1)->next->order > (*lst1)->next->next->order)
			a_three_321(lst1, lst2);
		else if ((*lst1)->next->next->order > (*lst1)->order)
			a_three_213(lst1);
		else
			a_three_312(lst1, lst2);
	}
	else
	{
		if ((*lst1)->order > (*lst1)->next->next->order)
			a_three_231(lst1, lst2);
		else if ((*lst1)->next->order > (*lst1)->next->next->order)
			a_three_132(lst1, lst2);
	}
}
