/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_four2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:55:56 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 15:56:05 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_four_1324(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_213(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_1423(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_312(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_1432(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_321(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_2431(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_321(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, lst2, 0);
}
