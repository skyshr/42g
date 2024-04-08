/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:34:39 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/08 16:34:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_singlearg(t_list **lst, char *argv)
{
	int	num;

	while (*argv)
	{
		if (!get_num(&argv, &num) || ft_lstiter(*lst, num, is_duplicate) \
			|| !ft_lstadd_back(lst, ft_lstnew(num)))
		{
			write(1, "Error\n", 6);
			ft_lstclear(lst);
			return (-1);
		}
		if (*argv == ' ')
			argv++;
	}
	return (1);
}

void	parse_multiarg(t_list **lst, int argc, char **argv)
{
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		if (parse_singlearg(lst, argv[idx]) == -1)
			return ;
		idx++;
	}
}

void	parse_data(t_list **lst, int argc, char **argv)
{
	if (argc == 2)
		parse_singlearg(lst, argv[1]);
	else
		parse_multiarg(lst, argc, argv);
}
