/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_three.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:02:45 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:02:47 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_three_132(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	swap(lst1, lst2, 0);
	push(lst2, lst1, 1);
}

void	a_three_213(t_list **lst1, t_list **lst2)
{
	swap(lst1, lst2, 0);
}

void	a_three_231(t_list **lst1, t_list **lst2)
{
	a_three_132(lst1, lst2);
	swap(lst1, lst2, 0);
}

void	a_three_312(t_list **lst1, t_list **lst2)
{
	swap(lst1, lst2, 0);
	a_three_132(lst1, lst2);
}

void	a_three_321(t_list **lst1, t_list **lst2)
{
	swap(lst1, lst2, 0);
	a_three_231(lst1, lst2);
}
