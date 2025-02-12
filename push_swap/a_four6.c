/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_four6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:58:48 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 15:58:49 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_four_3124(t_list **lst1, t_list **lst2)
{
	swap(lst1, lst2, 0);
	push(lst1, lst2, 0);
	a_three_213(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_4123(t_list **lst1, t_list **lst2)
{
	swap(lst1, lst2, 0);
	push(lst1, lst2, 0);
	a_three_312(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_4132(t_list **lst1, t_list **lst2)
{
	swap(lst1, lst2, 0);
	push(lst1, lst2, 0);
	a_three_321(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_4231(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2, 2);
	rotate(lst1, lst2, 0);
	push(lst2, lst1, 1);
	swap(lst1, lst2, 0);
	push(lst2, lst1, 1);
	reverse_rotate(lst1, lst2, 0);
}
