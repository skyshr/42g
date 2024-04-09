/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_four2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:22:08 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:22:09 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_four_2314(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst2, lst1, 0);
	rotate_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
	swap(lst2, lst1, 0);
	reverse_rotate_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
}

void	b_four_2413(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
	swap(lst2, lst1, 0);
	push(lst1, lst2, 1);
}

void	b_four_3412(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_four_3421(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst2, lst1, 0);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}
