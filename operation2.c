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

void	rotate_both(t_list **lst1, t_list **lst2, int sign)
{
	rotate(lst1, lst2, 2);
	rotate(lst2, lst1, 2);
    if (sign == 2)
	    write(1, "rr\n", 3);
}

void	reverse_rotate_both(t_list **lst1, t_list **lst2, int sign)
{
	reverse_rotate(lst1, lst2, 2);
	reverse_rotate(lst2, lst1, 2);
    if (sign == 2)
	    write(1, "rrr\n", 4);
}

void	push_rotate(t_list **lst1, t_list **lst2, int sign)
{
	push(lst1, lst2, sign);
	rotate(lst2, lst1, sign == 0);
}
