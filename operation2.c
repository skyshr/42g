/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:16:10 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:16:12 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_list **lst1, t_list **lst2)
{
	rotate(lst1, 2);
	rotate(lst2, 2);
	printf("rr\n");
}

void	reverse_rotate_both(t_list **lst1, t_list **lst2)
{
	reverse_rotate(lst1, 2);
	reverse_rotate(lst2, 2);
	printf("rrr\n");
}

void	push_rotate(t_list **lst1, t_list **lst2, int sign)
{
	push(lst1, lst2, sign);
	rotate(lst2, sign == 0);
}