/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_four3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:56:49 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 15:56:51 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_four_2314(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_213(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, lst2, 0);
}

void	a_four_2413(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	swap(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2, 2);
	push(lst2, lst1, 1);
	push(lst2, lst1, 1);
}

void	a_four_3412(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	swap(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2, 2);
	push(lst2, lst1, 1);
	swap(lst1, lst2, 0);
	push(lst2, lst1, 1);
}

void	a_four_3421(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	swap(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2, 2);
	push(lst2, lst1, 1);
	swap(lst1, lst2, 0);
	push(lst2, lst1, 1);
	swap(lst1, lst2, 0);
}
