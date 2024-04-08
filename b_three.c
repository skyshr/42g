/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_three.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:26:34 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:26:35 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_three_231(t_list **lst1, t_list **lst2)
{
	swap(lst1, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_three_123(t_list **lst1, t_list **lst2)
{
	swap(lst1, 1);
	b_three_213(lst1, lst2);
}

void	b_three_132(t_list **lst1, t_list **lst2)
{
	swap(lst1, 1);
	b_three_312(lst1, lst2);
}

void	b_three_312(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	swap(lst1, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}
