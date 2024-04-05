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

int	is_ordered(t_list *lst,	int	flag, size_t size)
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
		{
			// printf("List is not ordered!\n");
			return (0);
		}
		i = cur->n;
		cur = cur->next;
	}
	// printf("List is ordered!\n");
	return (1);
}

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
	// printf("get_num success!\n");
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
	printf("\n\n------------ORDER------------\n");
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
		parse_single_arg(lst, argv[1]);
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
	if (!tmp || !(*lst)->next)
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
	if (!tmp || !(*lst)->next)
		return ;
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(lst, tmp);
	(*cnt)++;
}

int	init(t_list **lst1, t_list **lst2, int n)
{
	int		pivot;
	int		size;
	int		cnt;

	pivot = n / 2;
	size = pivot;
	cnt = 0;
	while (size)
	{
		if ((*lst1)->order <= pivot)
		{
			push(lst1, lst2, &cnt);
			size--;
		}
		else
			rotate(lst1, &cnt);
	}
	return (cnt);
}

// 5 15


// 1. n = 20, sector = 8
// pivot = 20 / 8 = 2
// 3(5 - 2),  7(5 + 2), 13(15 - 2), 17(15 + 2)

// 2. n = 20, sector = 16
// pivot = 20 / 16 = 1
// 2(3 - 1), 4(3 + 1), 6(7 - 1), 8(7 + 1), 12(13 - 1), 14(15 + 1), 16(17 - 1), 18(17 + 1)


int	divide_conquer(t_list **lst1, t_list **lst2, int left, int right)
{
	t_list	*cur;
	int		pivot;
	int		cnt;
	int		s;

	pivot = (left + right) / 2;
	if (left >= right)
		return (0);
	// printf("left, right, pivot: %d, %d, %d\n", left, right, pivot);
	cnt = 0;
	s = right - left + 1;
	// if (is_ordered(*lst1, 0, s))
	// {
	// 	return (0);
	// }
	if (is_ordered(*lst1, 0, s))
		return (0);
	if (s == 2)
	{
		print_list(*lst1);
		swap(lst1, &cnt);
		print_list(*lst1);
		return (1);
	}
	while ((*lst1)->order != pivot)
	{
		if ((*lst1)->order > pivot && (*lst1)->order <= right)
			push(lst1, lst2, &cnt);
		else if ((*lst1)->next && (*lst1)->next->order < (*lst1)->order && \
			(*lst1)->next->order <= pivot && (*lst1)->next->order >= left && \
			(*lst1)->order <= pivot && (*lst1)->order >= left)
		{
			swap(lst1, &cnt);
			rotate(lst1, &cnt);
		}
		else
			rotate(lst1, &cnt);
		s--;
	}
	// printf("1\n");
	// print_list(*lst1);
	// print_list(*lst2);
	while (s--)
	{
		if ((*lst1)->order < pivot && (*lst1)->order >= left)
		{
			push(lst1, lst2, &cnt);
			rotate(lst2, &cnt);
		}
		else if ((*lst1)->next && (*lst1)->next->order < (*lst1)->order && \
			(*lst1)->next->order <= pivot && (*lst1)->next->order >= left && \
			(*lst1)->order <= pivot && (*lst1)->order >= left)
		{
			swap(lst1, &cnt);
			rotate(lst1, &cnt);
		}
		else
			rotate(lst1, &cnt);
	}
	// printf("2\n");
	// print_list(*lst1);
	// return (0);
	while ((*lst1)->order != pivot)
		reverse_rotate(lst1, &cnt);
	// printf("3\n");
	// print_list(*lst1);
	rotate(lst1, &cnt);	
	while ((*lst2)->order <= right && (*lst2)->order > pivot)
		push(lst2, lst1, &cnt);
	// printf("4\n");
	// print_list(*lst1);
	// print_list(*lst2);
	// return (0);
	while ((*lst1)->order != pivot)
		rotate(lst1, &cnt);
	// printf("5\n");
	// print_list(*lst1);
	// print_list(*lst2);
	// return (0);
	cur = ft_lstlast(*lst2);
	s = pivot - left - 1;
	while (cur->order >= left && cur->order <= pivot)
	{
		cur = cur->prev;
		reverse_rotate(lst2, &cnt);
		push(lst2, lst1, &cnt);
		s--;
	}
	// printf("6\n");
	// print_list(*lst1);
	// print_list(*lst2);
	// return (0);
	// printf("s: %d\n", s);
	cur = ft_lstlast(*lst1);
	while (s-- >= 0)
	{
		cur = cur->prev;
		reverse_rotate(lst1, &cnt);
	}
	// printf("7\n");
	// print_list(*lst1);
	// print_list(*lst2);
	cnt += divide_conquer(lst1, lst2, left, pivot - 1);
	// printf("8\n");
	while ((*lst1)->order != pivot)
		rotate(lst1, &cnt);
	// printf("9\n");
	rotate(lst1, &cnt);
	// print_list(*lst1);
	// print_list(*lst2);
	cnt += divide_conquer(lst1, lst2, pivot + 1, right);
	// printf("10\n");
	return (cnt);
}

int	divide_conquer1(t_list **lst1, t_list **lst2, int left, int right)
{
	t_list	*cur;
	int		pivot;
	int		cnt;
	int		s;

	pivot = (left + right) / 2;
	if (left >= right)
		return (0);
	// printf("div 1, left, right, pivot: %d, %d, %d\n", left, right, pivot);
	cnt = 0;
	s = right - left + 1;
	if (is_ordered(*lst1, 1, s))
		return (0);
	if (s == 2)
	{
		print_list(*lst1);
		swap(lst1, &cnt);
		print_list(*lst1);
		return (1);
	}
	// if (is_ordered(*lst1, 1, s))
	// {
	// 	return (0);
	// }
	while ((*lst1)->order != pivot)
	{
		if ((*lst1)->order < pivot && (*lst1)->order >= left)
		{
			push(lst1, lst2, &cnt);
			rotate(lst2, &cnt);
		}
		// else if ((*lst1)->next && (*lst1)->next->order > (*lst1)->order && \
		// 	(*lst1)->next->order >= pivot && (*lst1)->next->order <= right && \
		// 	(*lst1)->order >= pivot && (*lst1)->order <= right)
		// {
		// 	swap(lst1, &cnt);
		// 	rotate(lst1, &cnt);
		// }
		else
			rotate(lst1, &cnt);
		s--;
	}
	// printf("11\n");
	while (s--)
	{
		if ((*lst1)->order > pivot && (*lst1)->order <= right)
			push(lst1, lst2, &cnt);
		// else if ((*lst1)->next && (*lst1)->next->order > (*lst1)->order && \
		// 		(*lst1)->next->order >= pivot && (*lst1)->next->order <= right && \
		// 		(*lst1)->order >= pivot && (*lst1)->order <= right)
		// {
		// 	swap(lst1, &cnt);
		// 	rotate(lst1, &cnt);
		// }
		else
			rotate(lst1, &cnt);
	}
	// printf("12\n");
	while ((*lst1)->order != pivot)
		reverse_rotate(lst1, &cnt);
	// printf("13\n");
	// print_list(*lst1);
	// print_list(*lst2);
	rotate(lst1, &cnt);
	cur = ft_lstlast(*lst2);
	s = right - pivot - 1;
	while (cur->order >= left && cur->order <= right)
	{
		cur = cur->prev;
		reverse_rotate(lst2, &cnt);
		push(lst2, lst1, &cnt);
	}
	// printf("14\n");
	// print_list(*lst1);
	// print_list(*lst2);
	reverse_rotate(lst1, &cnt);
	while ((*lst2)->order <= right && (*lst2)->order >= pivot)
	{
		push(lst2, lst1, &cnt);
		s--;
	}
	// printf("15\n");
	// print_list(*lst1);
	// print_list(*lst2);
	while (s-- >= 0)
		reverse_rotate(lst1, &cnt);
	// print_list(*lst1);
	// print_list(*lst2);
	// return (0);
	// while ((*lst1)->order != pivot)
	// 	rotate(lst1, &cnt);
	// cur = ft_lstlast(*lst2);
	// rotate(lst1, &cnt);
	// cur = ft_lstlast(*lst1);
	// printf("16\n");
	// print_list(*lst1);
	// print_list(*lst2);
	cnt += divide_conquer1(lst1, lst2, pivot + 1, right);
	// printf("17\n");
	// print_list(*lst1);
	// print_list(*lst2);
	while ((*lst1)->order != pivot)
		rotate(lst1, &cnt);
	rotate(lst1, &cnt);
	// printf("18\n");
	cnt += divide_conquer1(lst1, lst2, left, pivot - 1);
	// printf("19\n");
	return (cnt);
}

int	adjust_merge(t_list **lst1, t_list **lst2, int n)
{
	int	cnt;

	cnt = 0;
	while ((*lst1)->order != n + 1)
		rotate(lst1, &cnt);
	while ((*lst2)->order != n)
		rotate(lst2, &cnt);
	while (*lst2)
		push(lst2, lst1, &cnt);
	return (cnt);
}

void	push_swap(t_list **lst1)
{
	t_list	*lst2;
	int		n;
	int		cnt;
	int		size;

	lst2 = NULL;
	if (!(*lst1))
		return ;
	n = ft_lstsize(*lst1);
	cnt = init(lst1, &lst2, n);
	size = n / 4;
	printf("init count: %d\n", cnt);
	if (!is_ordered(*lst1, 0, n - n / 2))
	{
		cnt += divide_conquer(lst1, &lst2, n / 2 + 1, n);
		printf("after conquer(lst1) count: %d\n", cnt);
	}
	if (!is_ordered(lst2, 1, n / 2))
		cnt += divide_conquer1(&lst2, lst1, 1, n / 2);
	printf("after conquer(lst2) count: %d\n", cnt);
	// print_list(*lst1);
	// print_list(lst2);
	cnt += adjust_merge(lst1, &lst2, n / 2);
	print_list(*lst1);
	// print_list(lst2);
	printf("count: %d\n", cnt);
	ft_lstclear(lst1);
	ft_lstclear(&lst2);
}


int	is_high(int m, int n)
{
	return (n > m);
}

void order_data(t_list **lst)
{
	t_list	*cur;

	if (!(*lst))
		return ;
	if (is_ordered(*lst, 0, ft_lstsize(*lst)))
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
	order_data(&lst);
	// print_list(lst);
	push_swap(&lst);
	// ft_lstclear(&lst);
	return (0);
}


// init
//A: 19 20 17 12 14 13 11 18 15 16 
//A: 12 14 13 11 15 16 18 17 20 19
//B: 9 7 10 6 8 5 3 1 2 4

// 1st d/c A:
// pivot: 13 => left: 4, right: 5, PREV_PIVOT = 15
// A: 15 16 18 17 20 19 12 13
// B: 14 9 7 10 6 8 5 3 1 2 4 11
// 14 15 16 18 17 20 19 12 13
// 12 11 13 14 15 16 18 17 20 19

// 2nd d/c A:
// pivot: 13 - 

// <25> 28 27 26 23 21 24 29 22 (30) 39 32 38 37 36 34 31 33 40 <35> 
// <23> 21 24 22 (25) 28 <27> 26 29 <<30>> 39 32 38 37 36 34 31 33 40 35
// 22 21 23 24 25 28 27 26 29 30 39 32 38 37 36 34 31 33 40 35
// 21 22 23 24 25 26 27 29 28 30 