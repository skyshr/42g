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
		return ;
	if (tmp->next)
		tmp->next->prev = NULL;
	*lst1 = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(lst2, tmp);
	if (!sign)
		printf("pb\n");
	else
		printf("pa\n");
}

void	swap(t_list **lst, int sign)
{
	t_list	*tmp;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *lst;
	tmp->prev = NULL;
	tmp->next = NULL;
	ft_lstadd_front(lst, tmp);
	if (!sign)
		printf("sa\n");
	else if (sign == 1)
		printf("sb\n");
}

void	rotate(t_list **lst, int sign)
{
	t_list	*tmp;

	tmp = *lst;
	if (!tmp || !(*lst)->next)
		return ;
	if (tmp->next)
		tmp->next->prev = NULL;
	*lst = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
	if (!sign)
		printf("ra\n");
	else if (sign == 1)
		printf("rb\n");
}

void	reverse_rotate(t_list **lst, int sign)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	if (!tmp || !(*lst)->next)
		return ;
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(lst, tmp);
	if (!sign)
		printf("rra\n");
	else if (sign == 1)
		printf("rrb\n");
}

void	swap_both(t_list **lst1, t_list **lst2)
{
	swap(lst1, 2);
	swap(lst2, 2);
	printf("ss\n");
}
