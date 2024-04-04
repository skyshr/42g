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
	if (**argv == '-' || **argv == '+')
	{
		if (**argv == '-')
			sign = -1;
		(*argv)++;
	}
	if (!ft_isdigit(**argv))
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
	printf("\n\n---------list----------\n\n");
	printf("------------VALUE------------\n");
	while (tmp)
	{
		printf("%d ", tmp->n);
		tmp = tmp->next;
	}
	tmp = lst;
	printf("------------ORDER------------\n");
	while (tmp)
	{
		printf("%d ", tmp->order);
		tmp = tmp->next;
	}
	printf("\n\n----------------------\n\n");
}

void	parse_single_arg(t_list **lst, char *argv)
{
	int	num;

	while (*argv)
	{
		if (!get_num(&argv, &num) || ft_lstiter(*lst, num, isduplicate) \
			|| !ft_lstadd_back(lst, ft_lstnew(num)))
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

void	push(t_list **lst1, t_list **lst2, int *cnt)
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
	(*cnt)++;
}

void	swap(t_list **lst, int *cnt)
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
	(*cnt)++;
}

void	rotate(t_list **lst, int *cnt)
{
	t_list	*tmp;

	tmp = *lst;
	if (!tmp)
		return ;
	if (tmp->next)
		tmp->next->prev = NULL;
	*lst = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
	(*cnt)++;
}

void	reverse_rotate(t_list **lst, int *cnt)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	if (!tmp)
		return ;
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(lst, tmp);
	(*cnt)++;
}

int	pivot_push()
{
	
}

void	init(t_list **lst1, t_list **lst2, int n)
{
	t_list	*cur;
	int		pivot;
	int		size;
	int		cnt;
	int		flag;

	pivot = n / 2;
	size = n - pivot;
	cnt = 0;
	while (size)
	{
		cur = *lst1;
		if (cur->order <= pivot)
		{
			cnt += pivot_push(lst1, lst2, cur->order, pivot / 2);
			size--;
		}
		else
			rotate(lst1, &cnt);
	}
	pivot += pivot / 2;
	size = pivot;
	flag = 0;
	while (size --)
	{
		cur = *lst1;
		if (cur->order > pivot)
		{
			if (!flag)
				push(lst1, lst2, &cnt);
			else
				rotate(lst1, &cnt);
		}
		else if (cur->order == pivot)
		{
			rotate(lst1, &cnt);
			flag = 1;
		}
		else{
			if (!flag)
				rotate(lst1, &cnt);
			else
			{
				push(lst1, lst2, &cnt);
				rotate(lst2, &cnt);
			}
		}
	}
	printf("count: %d\n", cnt);
}

void	push_swap(t_list **lst1)
{
	t_list	*lst2;
	int		n;
	int		cnt;

	lst2 = NULL;
	if (!(*lst1))
		return ;
	n = ft_lstsize(*lst1);
	init(lst1, &lst2, n);
	printf("\nLST1\n");
	print_list(*lst1);
	printf("\nLST2\n");
	print_list(lst2);
	ft_lstclear(lst1);
	ft_lstclear(&lst2);
}

int	is_ordered(t_list *lst)
{
	t_list	*cur;
	int		i;

	cur = lst;
	i = -2147483648;
	while (cur)
	{
		if (cur->n < i)
		{
			printf("List is not ordered!\n");
			return (0);
		}
		i = cur->n;
		cur = cur->next;
	}
	printf("List is ordered!\n");
	return (1);
}

int	is_high(int m, int n)
{
	return (m > n);
}

void order_data(t_list **lst)
{
	t_list	*cur;

	if (!(*lst))
		return ;
	if (is_ordered(*lst))
	{
		ft_lstclear(lst);
		return ;
	}
	cur = *lst;
	while (cur)
	{
		cur->order = ft_lstiter(*lst, cur->n, is_high) + 1;
		cur = cur->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst;

	lst = NULL;
	parse_data(&lst, argc, argv);
	// print_list(lst);
	order_data(&lst);
	push_swap(&lst);
	// ft_lstclear(&lst);
	return (0);
}
