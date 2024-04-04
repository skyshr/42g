/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:51:28 by ksuh              #+#    #+#             */
/*   Updated: 2024/02/27 17:52:55 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstiter(t_list *lst, int n, int (*f)(int, int))
{
	t_list	*tmp;
	int		res;

	tmp = lst;
	res = 0;
	if (!f || !tmp)
		return (res);
	while (tmp)
	{
		res += f(tmp->n, n);
		tmp = tmp->next;
	}
	return (res);
}
