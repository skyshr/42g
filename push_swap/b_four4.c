/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_four4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:23:57 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:23:58 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_four_3214(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	rotate_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
	swap(lst2, lst1, 0);
	reverse_rotate_both(lst1, lst2, 2);
	push(lst1, lst2, 1);
}

void	b_four_4213(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	b_three_213(lst1, lst2);
}

void	b_four_4312(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	b_three_312(lst1, lst2);
}
