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

void	parse_singlearg(t_list **lst, char *argv)
{
	int	num;

	if (!*argv)
	{
		ft_lstclear(lst);
		write(1, "Error\n", 6);
		exit(1);
	}
	while (*argv)
	{
		if (!get_num(&argv, &num) || ft_lstiter(*lst, num, is_duplicate) \
			|| !ft_lstadd_back(lst, ft_lstnew(num)))
		{
			ft_lstclear(lst);
			write(1, "Error\n", 6);
			exit(1);
		}
		if (*argv == ' ')
			argv++;
	}
}

void	parse_multiarg(t_list **lst, int argc, char **argv)
{
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		parse_singlearg(lst, argv[idx]);
		idx++;
	}
}

void	parse_data(t_list **lst, int argc, char **argv)
{
	if (argc < 2)
		exit(1);
	if (argc == 2)
		parse_singlearg(lst, argv[1]);
	else
		parse_multiarg(lst, argc, argv);
}
