/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:59:27 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 20:59:28 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_error(t_list **lst1, t_list **lst2)
{
	ft_lstclear(lst1);
	ft_lstclear(lst2);
	write(1, "Error\n", 6);
	exit(1);
}

void	lst_error_bonus(t_list **lst1, t_list **lst2, char *s)
{
	free(s);
	s = NULL;
	lst_error(lst1, lst2);
}
