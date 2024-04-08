/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:37:03 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 19:37:05 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_list *lst, int size)
{
	int	sz;

	sz = ft_lstsize(lst);
	if (sz != size || !is_ordered(lst, 0, size))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	handle_operation(t_list **lst1, t_list **lst2, char *s, int len)
{
	if (ft_strncmp(s, "pa", len) == 0)
		push(lst2, lst1, 1);
	else if (ft_strncmp(s, "pb", len) == 0)
		push(lst1, lst2, 0);
	else if (ft_strncmp(s, "sa", len) == 0)
		swap(lst1, 0);
	else if (ft_strncmp(s, "sb", len) == 0)
		swap(lst2, 1);
	else if (ft_strncmp(s, "ss", len) == 0)
		swap_both(lst1, lst2, 2);
	else if (ft_strncmp(s, "ra", len) == 0)
		rotate(lst1, 0);
	else if (ft_strncmp(s, "rb", len) == 0)
		rotate(lst2, 1);
	else if (ft_strncmp(s, "rr", len) == 0)
		rotate(lst1, 2);
	else if (ft_strncmp(s, "rra", len) == 0)
		rotate(lst1, 0);
	else if (ft_strncmp(s, "rrb", len) == 0)
		rotate(lst1, 1);
	else if (ft_strncmp(s, "rrr", len) == 0)
		rotate(lst1, 2);
	else
		return (0);
	return (1);
}

int	is_validstr(t_list **lst1, t_list **lst2, char *s)
{
	int	idx;

	idx = 0;
	while (s[idx] != '\n')
	{
		if (idx > 2 || !ft_isalpha(s[idx]))
			return (0);
		idx++;
	}
	return (handle_operation(lst1, lst2, s, idx));
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*lst1;
	t_list	*lst2;
	char	*s;
	int		size;

	lst1 = NULL;
	lst2 = NULL;
	parse_data(&lst1, argc, argv);
	size = ft_lstsize(lst1);
	order_data(&lst1, size);
	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		if (!is_validstr(&lst1, &lst2, s))
		{
			ft_lstclear(&lst1);
			ft_lstclear(&lst2);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(s);
	}
	checker(lst1, size);
	ft_lstclear(&lst1);
	ft_lstclear(&lst2);
	return (0);
}
