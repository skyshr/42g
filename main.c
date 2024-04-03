/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:24:12 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/03 11:24:18 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	get_num(char **argv, int *num)
{
	unsigned int	n;
	int				sign;

	n = 0;
	sign = 1;
	if (**argv == '-')
	{
		sign = -1;
		(*argv)++;
	}
	if (!ft_isdigit(**argv) || **argv == '0')
	{
		printf("Only digits are allowed!, %d\n", **argv);
		return (0);
	}
	while (ft_isdigit(**argv))
	{
		n = n * 10 + **argv - '0';
		if (n > (unsigned int)(2147483647 + (sign == -1)))
		{
			printf("Overflow detected!\n");
			return (0);
		}
		(*argv)++;
	}
	*num = (int)(sign * n);
	printf("get_num success!\n");
	return ((**argv == ' ' && *(*argv + 1)) || !**argv);
}

int	isduplicate(int n, int m)
{
	return (n == m);
}

void	print_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("value: %d\n", tmp->n);
		tmp = tmp->next;
	}
}

void	parse_single_arg(t_list **lst, char *argv)
{
	int	num;

	while (*argv)
	{
		if (get_num(&argv, &num) && ft_lstiter(*lst, num, isduplicate) \
			&& ft_lstadd_back(lst, ft_lstnew(num)))
		{
			printf("%d added to list succesfully!\n", num);
			// print_list(*lst);
		}
		else 
		{
			printf("Error detected!\n");
			ft_lstclear(lst);
			return ;
		}
		if (*argv == ' ')
			argv++;
	}
}

void	parse_data(t_list **lst, int argc, char **argv)
{
	if (argc == 2)
	{
		parse_single_arg(lst, argv[1]);
	}
	// else
	// {

	// }
}


int	main(int argc, char **argv)
{
	t_list	*lst;

	lst = NULL;
	parse_data(&lst, argc, argv);
	print_list(lst);
	// push_swap(&lst);
	ft_lstclear(&lst);
	return (0);
}
