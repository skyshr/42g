/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_four1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:22:03 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:22:03 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_four_1234(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	reverse_rotate(lst1, 1);
	push(lst1, lst2, 1);
	reverse_rotate(lst2, 0);
}

void	b_four_1243(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	reverse_rotate(lst1, 1);
	push(lst1, lst2, 1);
	reverse_rotate(lst2, 0);
}

void	b_four_1342(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate(lst2, 0);
	b_three_231(lst1, lst2);
	reverse_rotate(lst2, 0);
}

void	b_four_2341(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	swap(lst1, 1);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	push(lst1, lst2, 1);
}
