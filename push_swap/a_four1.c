/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_four1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:54:25 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 15:54:27 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_four_2341(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_231(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, lst2, 0);
}

void	a_four_1243(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_132(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_1342(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_231(lst1, lst2);
	push(lst2, lst1, 1);
}
