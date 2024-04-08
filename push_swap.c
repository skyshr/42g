/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:38:02 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 22:38:03 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **lst1, int size)
{
	t_list	*lst2;

	lst2 = NULL;
	if (!(*lst1) || is_ordered(lst1, 0, size))
		return ;
	if (size <= 5)
	{
		bfs(lst1, lst2, size);
		return ;
	}
	a_to_b(lst1, &lst2, 0, size);
	ft_lstclear(&lst2);
}
