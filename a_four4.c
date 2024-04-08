/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_four4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:57:41 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 15:57:42 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_four_3214(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	a_three_213(lst1);
	push(lst2, lst1, 1);
	swap(lst1, 0);
}

void	a_four_4321(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, 0);
	push(lst2, lst1, 1);
	swap(lst1, 0);
}

void	a_four_4312(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, 0);
	push(lst2, lst1, 1);
}

void	a_four_4213(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	push(lst2, lst1, 1);
}
