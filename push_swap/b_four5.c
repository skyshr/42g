/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_four5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:24:01 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:24:04 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_four_2134(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst2, lst1, 0);
	reverse_rotate_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
}

void	b_four_2143(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	reverse_rotate_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
}

void	b_four_3142(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	swap(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_four_3241(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	swap(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst2, lst1, 0);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}
