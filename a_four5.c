/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_four5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:58:37 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 15:58:38 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_four_2134(t_list **lst1)
{
	swap(lst1, 0);
}

void	a_four_2143(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	push(lst2, lst1, 1);
}

void	a_four_3142(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, 0);
	push(lst2, lst1, 1);
}

void	a_four_3241(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	rotate(lst1, 0);
	push(lst2, lst1, 1);
	push(lst2, lst1, 1);
	reverse_rotate(lst1, 0);
}
