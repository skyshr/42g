/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:39:05 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:39:06 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_list *lst, int flag, size_t size)
{
	t_list	*cur;
	int		i;

	cur = lst;
	i = -2147483648;
	if (flag)
		i = 2147483647;
	while (size--)
	{
		if ((!flag && cur->n < i) || (flag && cur->n > i))
			return (0);
		i = cur->n;
		cur = cur->next;
	}
	return (1);
}

int	get_num(char **argv, int *num)
{
	unsigned long long  n;
	int				    sign;

	n = 0;
	sign = 1;
	if (**argv == '-' || **argv == '+')
	{
		if (**argv == '-')
			sign = -1;
		(*argv)++;
	}
	if (!ft_isdigit(**argv))
		return (0);
	while (ft_isdigit(**argv))
	{
		n = n * 10 + **argv - '0';
		if (n > (unsigned long long)2147483647 + (sign == -1))
			return (0);
		(*argv)++;
	}
	*num = (int)(sign * n);
	return (((**argv) == ' ' && (*(*argv + 1))) || !(**argv));
}

void	order_data(t_list **lst, int size)
{
	t_list	*cur;

	if (!size)
		return ;
	cur = *lst;
	while (cur)
	{
		cur->order = ft_lstiter(*lst, cur->n, is_high) + 1;
		cur = cur->next;
	}
}

int	is_high(int m, int n)
{
	return (n > m);
}

int	is_duplicate(int n, int m)
{
	return (n == m);
}
