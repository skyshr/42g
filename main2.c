/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:45:54 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/05 18:45:58 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

static void    a_to_b(t_list **lst1, t_list **lst2, int left, int right);
static void    b_to_a(t_list **lst1, t_list **lst2, int left, int right);

int ps = 0;
int rt = 0;
int rrt = 0;
int sp = 0;

void	print_operations()
{
	printf("ps, rt, rrt, sp: %d, %d, %d, %d\n", ps, rt, rrt, sp);
}

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

	// tmp = lst;
	// printf("\n\n---------list----------\n\n");
	// printf("------------VALUE------------\n");
	// while (tmp)
	// {
	// 	printf("%d ", tmp->n);
	// 	tmp = tmp->next;
	// }
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

void	push(t_list **lst1, t_list **lst2)
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
	// printf("p\n");
	ps++;
}

void	swap(t_list **lst)
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
	// printf("s\n");
	sp++;
}

void	rotate(t_list **lst)
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
	// printf("r\n");
	rt++;
}

void	reverse_rotate(t_list **lst)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	if (!tmp || !(*lst)->next)
		return ;
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(lst, tmp);
	// printf("rr\n");
	rrt++;
}

void    b_to_a(t_list **lst1, t_list **lst2, int left, int right)
{
    int pivot;
    int spivot;
    int cnt;
    int size;

    size = right - left;
    // printf("b left, right: %d, %d\n", left, right);
    if (size == 1)
    {
        push(lst1, lst2);
        return ;
    }
    if (size == 2)
    {
        if (!is_ordered(*lst1, 1, 2))
            swap(lst1);
        push(lst1, lst2);
        push(lst1, lst2);
        // printf("B---------------------\n");
        // print_list(*lst1);
        // print_list(*lst2);
        return ;
    }
    pivot = size / 3;
    if (size % 3 == 2)
        pivot++;
    cnt = size;
    spivot = left + 2 * pivot;
    pivot += left;
    // printf("pivot, spivot: %d, %d\n", pivot, spivot);
    while (cnt--)
    {
        if ((*lst1)->order <= pivot)
            rotate(lst1);
        else if ((*lst1)->order <= spivot)
        {
            push(lst1, lst2);
            rotate(lst2);
        }
        else
            push(lst1, lst2);
    }
    // print_list(*lst1);
    // print_list(*lst2);
    if (!is_ordered(*lst2, 0, right - spivot))
        a_to_b(lst2, lst1, spivot, right);
    cnt = pivot - left;
    // printf("cnt: %d\n", cnt);
    while (cnt--)
    {
        reverse_rotate(lst1);
        reverse_rotate(lst2);
        rrt--;
    }
    // printf("B---------------------\n");
    // print_list(*lst1);
    // print_list(*lst2);
    if (!is_ordered(*lst2, 0, spivot - pivot))
        a_to_b(lst2, lst1, pivot, spivot);
    b_to_a(lst1, lst2, left, pivot);
    // printf("pivot, spivot: %d, %d\n", pivot, spivot);
}

void    a_to_b(t_list **lst1, t_list **lst2, int left, int right)
{
    int pivot;
    int spivot;
    int cnt;
    int size;

    size = right - left;
    if (is_ordered(*lst1, 0, size))
        return ;
    if (size == 2)
    {
        swap(lst1);
        return ;
    }
    pivot = size / 3;
    spivot = left + size / 3;
    if (size % 3 == 1)
        pivot++;
    else if (size % 3 == 2)
        spivot++;
    spivot += pivot;
    pivot += left;
    cnt = size;
    // printf("a left, right: %d, %d\n", left, right);
    // printf("pivot, spivot: %d, %d\n", pivot, spivot);
    while (cnt--)
    {
        if ((*lst1)->order <= pivot)
            push(lst1, lst2);
        else if ((*lst1)->order <= spivot)
        {
            push(lst1, lst2);
            rotate(lst2);
        }
        else
            rotate(lst1);
    }
    cnt = right - spivot;
    // printf("cnt: %d\n", cnt);
    // print_list(*lst1);
    // print_list(*lst2);
    while (cnt--)
    {
        reverse_rotate(lst1);
        reverse_rotate(lst2);
        rrt--;
    }
    print_list(*lst1);
    print_list(*lst2);
    if (!is_ordered(*lst1, 0, right - spivot))
        a_to_b(lst1, lst2, spivot, right);
    // printf("pivot, spivot: %d, %d\n", pivot, spivot);
    b_to_a(lst2, lst1, pivot, spivot);
    b_to_a(lst2, lst1, left, pivot);
    // printf("pivot, spivot: %d, %d\n", pivot, spivot);
}

void	push_swap(t_list **lst1)
{
	t_list	*lst2;
    int     size;

	lst2 = NULL;
    size = ft_lstsize(*lst1);
	if (!(*lst1))
		return ;
    a_to_b(lst1, &lst2, 0, size);
    print_operations();
    print_list(*lst1);
    print_list(lst2);
    if (!is_ordered(*lst1, 0, size))
		printf("List is not ordered!!!!\n");
    printf("total: %d\n", ps + sp + rt + rrt);
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