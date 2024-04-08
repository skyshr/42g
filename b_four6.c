/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_four6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:24:07 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:24:08 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_four_3124(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate(lst1, 1);
	swap(lst1, 1);
	push(lst1, lst2, 1);
	reverse_rotate(lst1, 1);
	swap_both(lst1, lst2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_four_4123(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	b_three_123(lst1, lst2);
}

void	b_four_4132(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	b_three_132(lst1, lst2);
}

void	b_four_4231(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	b_three_231(lst1, lst2);
}
