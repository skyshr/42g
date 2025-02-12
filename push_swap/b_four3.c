/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_four3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:22:12 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:22:13 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_four_1324(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate(lst2, lst1, 0);
	b_three_213(lst1, lst2);
	reverse_rotate(lst2, lst1, 0);
}

void	b_four_1423(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate(lst2, lst1, 0);
	b_three_312(lst1, lst2);
	reverse_rotate(lst2, lst1, 0);
}

void	b_four_1432(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate(lst2, lst1, 0);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	reverse_rotate(lst2, lst1, 0);
}

void	b_four_2431(t_list **lst1, t_list **lst2)
{
	swap(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst1, lst2, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}
