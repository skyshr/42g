/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:15:33 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:15:34 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst1, t_list **lst2, int sign)
{
	t_list	*tmp;

	tmp = *lst1;
	if (!tmp)
		lst_error(lst1, lst2);
	if (tmp->next)
		tmp->next->prev = NULL;
	*lst1 = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(lst2, tmp);
	if (!sign)
		write(1, "pb\n", 3);
	else if (sign == 1)
		write(1, "pa\n", 3);
}

void	swap(t_list **lst1, t_list **lst2, int sign)
{
	t_list	*tmp;

	if (!(*lst1) || !(*lst1)->next)
		lst_error(lst1, lst2);
	tmp = (*lst1)->next;
	(*lst1)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *lst1;
	tmp->prev = NULL;
	tmp->next = NULL;
	ft_lstadd_front(lst1, tmp);
	if (!sign)
		write(1, "sa\n", 3);
	else if (sign == 1)
		write(1, "sb\n", 3);
}

void	rotate(t_list **lst1, t_list **lst2, int sign)
{
	t_list	*tmp;

	tmp = *lst1;
	if (!tmp || !(*lst1)->next)
		lst_error(lst1, lst2);
	if (tmp->next)
		tmp->next->prev = NULL;
	*lst1 = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(lst1, tmp);
	if (!sign)
		write(1, "ra\n", 3);
	else if (sign == 1)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_list **lst1, t_list **lst2, int sign)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst1);
	if (!tmp || !(*lst1)->next)
		lst_error(lst1, lst2);
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(lst1, tmp);
	if (!sign)
		write(1, "rra\n", 4);
	else if (sign == 1)
		write(1, "rrb\n", 4);
}

void	swap_both(t_list **lst1, t_list **lst2, int sign)
{
	swap(lst1, lst2, sign);
	swap(lst2, lst2, sign);
	if (sign == 2)
		write(1, "ss\n", 3);
}
