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

#include "push_swap.h"

int ps = 0;
int rt = 0;
int rrt = 0;
int sp = 0;

void	print_operations(void)
{
	printf("ps, rt, rrt, sp: %d, %d, %d, %d\n", ps, rt, rrt, sp);
}

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

int	is_duplicate(int n, int m)
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

int	parse_singlearg(t_list **lst, char *argv)
{
	int	num;

	while (*argv)
	{ 
		if (!get_num(&argv, &num) || ft_lstiter(*lst, num, is_duplicate) \
			|| !ft_lstadd_back(lst, ft_lstnew(num)))
		{
			printf("Error detected!\n");
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
	int	num;
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		if (parse_single_arg(lst, argv[idx]) == -1)
			return ;
		idx++;
	}
}

void	parse_data(t_list **lst, int argc, char **argv)
{
	if (argc == 2)
		parse_single_arg(lst, argv[1]);
	else
		parse_multi_arg(lst, argc,argv);
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
	printf("p\n");
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
	printf("s\n");
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
	printf("rt\n");
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
	printf("rrt\n");
	rrt++;
}

void	swap_both(t_list **lst1, t_list **lst2)
{
	swap(lst1);
	swap(lst2);
	sp--;
}

void	rotate_both(t_list **lst1, t_list **lst2)
{
	rotate(lst1);
	rotate(lst2);
	rt--;
}

void	reverse_rotate_both(t_list **lst1, t_list **lst2)
{
	reverse_rotate(lst1);
	reverse_rotate(lst2);
	rrt--;
}

void	push_rotate(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	rotate(lst2);
}

void	b_four_first(t_list **lst1, t_list **lst2)
{
	// 1 2 3 4
	if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		b_four_1234(lst1, lst2);
	// 1 2 4 3 - 5
	else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		b_four_1243(lst1, lst2);
	// 1 3 4 2 - 6
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		b_four_1342(lst1, lst2);
    // 2 3 4 1 - 7
    else
		b_four_2341(lst1, lst2);
}

void	b_four_second(t_list **lst1, t_list **lst2)
{
	// 2 3 1 4 - 4
	if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		b_four_2314(lst1, lst2);
	// 2 4 1 3 - 6
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		b_four_2413(lst1, lst2);
	// 3 4 1 2 - 7
	else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		b_four_3412(lst1, lst2);
	// 3 4 2 1 - 8
	else
		b_four_3421(lst1, lst2);
}

void	b_four_third(t_list **lst1, t_list **lst2)
{
	// 1 3 2 4 - 3
	if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		b_four_1324(lst1, lst2);
	// 1 4 2 3 - 6
	else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		b_four_1423(lst1, lst2);
	// 1 4 3 2 - 7
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		b_four_1432(lst1, lst2);
	// 2 4 3 1 - 8
	else
		b_four_2431(lst1, lst2);
}

void	b_four_fourth(t_list **lst1, t_list **lst2)
{
	// 3 2 1 4 - 5
	if ((*lst1)->next->next->next->order > (*lst1)->order)
		b_four_3214(lst1, lst2);
	// 4 2 1 3 - 7
	else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		b_four_4213(lst1, lst2);
	// 4 3 1 2 - 8
	else
		b_four_4312(lst1, lst2);
}

void	b_four_fifth(t_list **lst1, t_list **lst2)
{
	// 2 1 3 4 - 1
	if ((*lst1)->next->next->order < (*lst1)->next->next->next->order)
		b_four_2134(lst1, lst2);
	// 2 1 4 3 - 5
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		b_four_2143(lst1, lst2);
	// 3 1 4 2 - 6
	else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		b_four_3142(lst1, lst2);
	// 3 2 4 1 - 7
	else
		b_four_3241(lst1, lst2);
}

void	b_four_sixth(t_list **lst1, t_list **lst2)
{
	// 3 1 2 4 - 4
	if ((*lst1)->order < (*lst1)->next->next->next->order)
		b_four_3124(lst1, lst2);
	// 4 1 2 3 - 7
	else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		b_four_4123(lst1, lst2);
	// 4 1 3 2 - 8
	else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		b_four_4132(lst1, lst2);
	// 4 2 3 1 - 8
	else
		b_four_4231(lst1, lst2);
}

void    b_four(t_list **lst1, t_list **lst2)
{
	// printf("-------------------------before--------------------------------\n");
	// printf("%d, %d, %d, %d\n", (*lst1)->order, (*lst1)->next->order, (*lst1)->next->next->order, (*lst1)->next->next->next->order);
    if ((*lst1)->order < (*lst1)->next->order)
    {
        if ((*lst1)->next->order < (*lst1)->next->next->order)
			b_four_first(lst1, lst2);
		else if ((*lst1)->order > (*lst1)->next->next->order)
			b_four_second(lst1, lst2);
		else
			b_four_third(lst1, lst2);
    }
	else
	{
		if ((*lst1)->next->order > (*lst1)->next->next->order)
			b_four_fourth(lst1, lst2);
		else if ((*lst1)->order < (*lst1)->next->next->order)
			b_four_fifth(lst1, lst2);
		else
			b_four_sixth(lst1, lst2);
	}
	// printf("%d, %d, %d, %d\n", (*lst1)->order, (*lst1)->next->order, (*lst1)->next->next->order, (*lst1)->next->next->next->order);
	// printf("\n----------------------------------------\n");
}

void	a_four_2341(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	a_three_231(lst1, lst2);
	push(lst2, lst1);
	swap(lst1);
}

void	a_four_1243(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	a_three_132(lst1, lst2);
	push(lst2, lst1);
}

void	a_four_1342(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	a_three_231(lst1, lst2);
	push(lst2, lst1);
}

void	a_four_1324(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	a_three_213(lst1);
	push(lst2, lst1);
}

void	a_four_1423(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	a_three_312(lst1, lst2);
	push(lst2, lst1);
}

void	a_four_1432(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	a_three_321(lst1, lst2);
	push(lst2, lst1);
}

void	a_four_2431(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	a_three_321(lst1, lst2);
	push(lst2, lst1);
	swap(lst1);
}

void	a_four_2314(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	a_three_213(lst1);
	push(lst2, lst1);
	swap(lst1);
}

void	a_four_2413(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst2, lst1);
	push(lst2, lst1);
}

void	a_four_3412(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst2, lst1);
	swap(lst1);
	push(lst2, lst1);
}

void	a_four_3421(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst2, lst1);
	swap(lst1);
	push(lst2, lst1);
	swap(lst1);
}

void	a_four_3214(t_list **lst1, t_list **lst2)
{
	swap(lst1);
	push(lst1, lst2);
	a_three_213(lst1);
	push(lst2, lst1);
	swap(lst1);
}

void	a_four_4321(t_list **lst1, t_list **lst2)
{
	swap(lst1);
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst2, lst1);
	swap(lst1);
	push(lst2, lst1);
	swap(lst1);
}

void	a_four_4312(t_list **lst1, t_list **lst2)
{
	swap(lst1);
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst2, lst1);
	swap(lst1);
	push(lst2, lst1);
}

void	a_four_4213(t_list **lst1, t_list **lst2)
{
	swap(lst1);
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst2, lst1);
	push(lst2, lst1);
}

void	a_four_2134(t_list **lst1, t_list **lst2)
{
	swap(lst1);
}

void	a_four_2143(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst2, lst1);
	push(lst2, lst1);
}

void	a_four_3142(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst2, lst1);
	swap(lst1);
	push(lst2, lst1);
}

void	a_four_3241(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	rotate(lst1);
	push(lst2, lst1);
	push(lst2, lst1);
	reverse_rotate(lst1);
}

void	a_four_3124(t_list **lst1, t_list **lst2)
{
	swap(lst1);
	push(lst1, lst2);
	a_three_213(lst1);
	push(lst2, lst1);
}

void	a_four_4123(t_list **lst1, t_list **lst2)
{
	swap(lst1);
	push(lst1, lst2);
	a_three_312(lst1, lst2);
	push(lst2, lst1);
}

void	a_four_4132(t_list **lst1, t_list **lst2)
{
	swap(lst1);
	push(lst1, lst2);
	a_three_321(lst1, lst2);
	push(lst2, lst1);
}

void	a_four_4231(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	rotate(lst1);
	push(lst2, lst1);
	swap(lst1);
	push(lst2, lst1);
	reverse_rotate(lst1);
}

void	a_four_first(t_list **lst1, t_list **lst2)
{
    // 2 3 4 1 - 7
    if ((*lst1)->next->next->next->order < (*lst1)->order)
		a_four_2341(lst1, lst2);
	// 1 2 4 3 - 5
	else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		a_four_1243(lst1, lst2);
	// 1 3 4 2 - 6
	else
		a_four_1342(lst1, lst2);
}

void	a_four_second(t_list **lst1, t_list **lst2)
{
	// 1 3 2 4 - 3
	if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		a_four_1324(lst1, lst2);
	// 1 4 2 3 - 6
	else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		a_four_1423(lst1, lst2);
	// 1 4 3 2 - 7
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		a_four_1432(lst1, lst2);
	// 2 4 3 1 - 8
	else
		a_four_2431(lst1, lst2);
}

void	a_four_third(t_list **lst1, t_list **lst2)
{
	// 2 3 1 4 - 4
	if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		a_four_2314(lst1, lst2);
	// 2 4 1 3 - 6
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		a_four_2413(lst1, lst2);
	// 3 4 1 2 - 7
	else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		a_four_3412(lst1, lst2);
	// 3 4 2 1 - 8
	else
		a_four_3421(lst1, lst2);
}

void	a_four_fourth(t_list **lst1, t_list **lst2)
{
	// 3 2 1 4 - 5
	if ((*lst1)->next->next->next->order > (*lst1)->order)
		a_four_3214(lst1, lst2);
	// 4 3 2 1 - 9
	else if ((*lst1)->next->next->next->order < (*lst1)->next->next->order)
		a_four_4321(lst1, lst2);
	// 4 3 1 2 - 8
	else if ((*lst1)->next->next->next->order < (*lst1)->next->order)
		a_four_4312(lst1, lst2);
	// 4 2 1 3 - 7
	else
		a_four_4213(lst1, lst2);
}

void	a_four_fifth(t_list **lst1, t_list **lst2)
{
	// 2 1 3 4 - 1
	if ((*lst1)->next->next->order < (*lst1)->next->next->next->order)
		a_four_2134(lst1, lst2);
	// 2 1 4 3 - 5
	else if ((*lst1)->next->next->next->order > (*lst1)->order)
		a_four_2143(lst1, lst2);
	// 3 1 4 2 - 6
	else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		a_four_3142(lst1, lst2);
	// 3 2 4 1 - 7
	else
		a_four_3241(lst1, lst2);
}

void	a_four_sixth(t_list **lst1, t_list **lst2)
{
	// 3 1 2 4 - 4
	if ((*lst1)->order < (*lst1)->next->next->next->order)
		a_four_3124(lst1, lst2);
	// 4 1 2 3 - 7
	else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
		a_four_4123(lst1, lst2);
	// 4 1 3 2 - 8
	else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
		a_four_4132(lst1, lst2);
	// 4 2 3 1 - 8
	else
		a_four_4231(lst1, lst2);
}

void    a_four(t_list **lst1, t_list **lst2)
{
	// printf("-------------------------before--------------------------------\n");
	// printf("%d, %d, %d, %d\n", (*lst1)->order, (*lst1)->next->order, (*lst1)->next->next->order, (*lst1)->next->next->next->order);
    if ((*lst1)->order < (*lst1)->next->order)
    {
        if ((*lst1)->next->order < (*lst1)->next->next->order)
			a_four_first(lst1, lst2);
		else if ((*lst1)->order < (*lst1)->next->next->order)
			a_four_second(lst1, lst2);
		else 
			a_four_third(lst1, lst2);
    }
	else
	{
		if ((*lst1)->next->order > (*lst1)->next->next->order)
			a_four_fourth(lst1, lst2);
		else if ((*lst1)->order < (*lst1)->next->next->order)
			a_four_fifth(lst1, lst2);
		else
			a_four_sixth(lst1, lst2);
	}
	// printf("%d, %d, %d, %d\n", (*lst1)->order, (*lst1)->next->order, (*lst1)->next->next->order, (*lst1)->next->next->next->order);
	// printf("\n----------------------------------------\n");
}

void	b_four_1234(t_list **lst1, t_list **lst2)
{
	//pa pa ss ra ra pa pa rra rra - 8 - o
	printf("1234");
	print_list(*lst1);
	push(lst1, lst2);
	rotate_both(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	swap(lst2);
	reverse_rotate(lst1);
	push(lst1, lst2);
	reverse_rotate(lst2);
	print_list(*lst2);
}

void	b_four_1243(t_list **lst1, t_list **lst2)
{
	// pa rr pa pa rrb pa rra - 7 - o
	printf("1243");
	print_list(*lst1);
	push(lst1, lst2);
	rotate_both(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	reverse_rotate(lst1);
	push(lst1, lst2);
	reverse_rotate(lst2);
	print_list(*lst2);
}

void	b_four_1324(t_list **lst1, t_list **lst2)
{
	// 8 - o
	printf("1324");
	print_list(*lst1);
	push(lst1, lst2);
	rotate(lst2);
	b_three_213(lst1, lst2);
	reverse_rotate(lst2);
	print_list(*lst2);
}

void	b_four_1342(t_list **lst1, t_list **lst2)
{
	// 7 - o
	printf("1324");
	print_list(*lst1);
	push(lst1, lst2);
	rotate(lst2);
	b_three_231(lst1, lst2);
	reverse_rotate(lst2);
	print_list(*lst2);
}

void	b_four_1423(t_list **lst1, t_list **lst2)
{
	// 7 - o
	printf("1423");
	print_list(*lst1);
	push(lst1, lst2);
	rotate(lst2);
	b_three_312(lst1, lst2);
	reverse_rotate(lst2);
	print_list(*lst2);
}

void	b_four_1432(t_list **lst1, t_list **lst2)
{
	// 6 - o
	printf("1432");
	print_list(*lst1);
	push(lst1, lst2);
	rotate(lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	reverse_rotate(lst2);
	print_list(*lst2);
}

void	b_four_2134(t_list **lst1, t_list **lst2)
{
	// pa sb ra pa sb pa sa rra pa
	// 7 - o
	printf("2134");
	print_list(*lst1);
	push(lst1, lst2);
	rotate_both(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	swap(lst2);
	reverse_rotate_both(lst1, lst2);
	push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_2143(t_list **lst1, t_list **lst2)
{
	// 6 - o
	printf("2143");
	print_list(*lst1);
	push(lst1, lst2);
	rotate_both(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	reverse_rotate_both(lst1, lst2);
	push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_2314(t_list **lst1, t_list **lst2)
{
	// pa pa ss ra pa sa rra pa
	// 8 - o
	printf("2314");
	print_list(*lst1);
	// pa pa sa rr pa sa rrr pa
	push(lst1, lst2);
	push(lst1, lst2);
	swap(lst2);
	rotate_both(lst1, lst2);
	push(lst1, lst2);
	swap(lst2);
	reverse_rotate_both(lst1, lst2);
	push(lst1, lst2);
	// push(lst1, lst2);
	// push(lst1, lst2);
	// swap_both(lst1, lst2);
	// rotate(lst1);
	// push(lst1, lst2);
	// swap(lst2);
	// reverse_rotate(lst1);
	// push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_2341(t_list **lst1, t_list **lst2)
{
	// sb pa sb pa sa pa pa - 7 - o
	printf("2341");
	print_list(*lst1);
	// pa sb pa sa pa sa pa
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap(lst2);
	push(lst1, lst2);
	swap(lst2);
	push(lst1, lst2);
	// swap(lst1);
	// push(lst1, lst2);
	// swap(lst1);
	// push(lst1, lst2);
	// swap(lst2);
	// push(lst1, lst2);
	// push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_2413(t_list **lst1, t_list **lst2)
{
	// pa pa ss pa sa pa - 6 - o
	printf("2413");
	print_list(*lst1);
	push(lst1, lst2);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst1, lst2);
	swap(lst2);
	push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_2431(t_list **lst1, t_list **lst2)
{
	// 6 - o
	printf("2431");
	print_list(*lst1);
	swap(lst1);
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_3124(t_list **lst1, t_list **lst2)
{
	// pa pa sb pa sa ra sa pa rra
	// pa rb rb pa rrb rrb ss pa pa
	// pa rb sb pa rrb ss pa pa - 8 - o
	printf("3124");
	print_list(*lst1);
	push(lst1, lst2);
	rotate(lst1);
	swap(lst1);
	push(lst1, lst2);
	reverse_rotate(lst1);
	swap_both(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_3142(t_list **lst1, t_list **lst2)
{
	// 6 - o
	printf("3142");
	print_list(*lst1);
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_3214(t_list **lst1, t_list **lst2)
{
	//  - 7 - o
	printf("3214");
	print_list(*lst1);
	push(lst1, lst2);
	push(lst1, lst2);
	rotate_both(lst1, lst2);
	push(lst1, lst2);
	swap(lst2);
	reverse_rotate_both(lst1, lst2);
	push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_3241(t_list **lst1, t_list **lst2)
{
	// pa sb pa sa pa pa - 6 - o
	printf("3241");
	print_list(*lst1);
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap(lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_3412(t_list **lst1, t_list **lst2)
{
	// 5 - o
	printf("3412");
	print_list(*lst1);
	push(lst1, lst2);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_3421(t_list **lst1, t_list **lst2)
{
	// 5 o
	printf("3421");
	print_list(*lst1);
	push(lst1, lst2);
	push(lst1, lst2);
	swap(lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	print_list(*lst2);
}

void	b_four_4123(t_list **lst1, t_list **lst2)
{
	// 7 - o
	printf("4123");
	print_list(*lst1);
	push(lst1, lst2);
	b_three_123(lst1, lst2);
	print_list(*lst2);
}

void	b_four_4132(t_list **lst1, t_list **lst2)
{
	// 6 - o
	printf("4132");
	print_list(*lst1);
	push(lst1, lst2);
	b_three_132(lst1, lst2);
	print_list(*lst2);
}

void	b_four_4213(t_list **lst1, t_list **lst2)
{
	// 6 - o
	printf("4213");
	print_list(*lst1);
	push(lst1, lst2);
	b_three_213(lst1, lst2);
	print_list(*lst2);
}

void	b_four_4231(t_list **lst1, t_list **lst2)
{
	// 5 - o
	printf("4231");
	print_list(*lst1);
	push(lst1, lst2);
	b_three_231(lst1, lst2);
	print_list(*lst2);
}

void	b_four_4312(t_list **lst1, t_list **lst2)
{
	// 5 - o
	printf("4312");
	print_list(*lst1);
	push(lst1, lst2);
	b_three_312(lst1, lst2);
	print_list(*lst2);
}

// 3
void    a_three_132(t_list **lst1, t_list **lst2)
{
	// 1 3 2
	push(lst1, lst2);
	swap(lst1);
	push(lst2, lst1);
}

// 1
void    a_three_213(t_list **lst)
{
	// 2 1 3
	swap(lst);
}

// 4
void    a_three_231(t_list **lst1, t_list **lst2)
{
	// 2 3 1
	a_three_132(lst1, lst2);
	swap(lst1);
}

// 4
void    a_three_312(t_list **lst1, t_list **lst2)
{
	// 3 1 2
	swap(lst1);
	a_three_132(lst1, lst2);
}

// 5
void    a_three_321(t_list **lst1, t_list **lst2)
{
	// 3 2 1
	swap(lst1);
	a_three_231(lst1, lst2);
}

void    b_two(t_list **lst1, t_list **lst2)
{
    swap(lst1);
    push(lst1, lst2);
    push(lst1, lst2);
}

// 6
void    b_three_123(t_list **lst1, t_list **lst2)
{
	// 1 2 3
	swap(lst1);
	b_three_213(lst1, lst2);
}

// 5
void    b_three_132(t_list **lst1, t_list **lst2)
{
	// 1 3 2
	swap(lst1);
	b_three_312(lst1, lst2);
}

// 5
void    b_three_213(t_list **lst1, t_list **lst2)
{
    // 2 1 3
    push(lst1, lst2);
    swap(lst1);
    push(lst1, lst2);
    swap(lst2);
    push(lst1, lst2);
}

// 4
void    b_three_231(t_list **lst1, t_list **lst2)
{
	// 2 3 1
	swap(lst1);
	push(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
}

// 4
void    b_three_312(t_list **lst1, t_list **lst2)
{
	// 3 1 2
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	push(lst1, lst2);
}

void	b_three(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->order > (*lst1)->next->order)
	{
	    // 2 1 3
	    if ((*lst1)->next->next->order > (*lst1)->order)
			b_three_213(lst1, lst2);
	    // 3 1 2
	    else if ((*lst1)->order > (*lst1)->next->next->order)
			b_three_312(lst1, lst2);
	}
	else
	{
	    // 2 3 1
	    if ((*lst1)->order > (*lst1)->next->next->order)
			b_three_231(lst1, lst2);
	    // 1 3 2
	    else if ((*lst1)->next->order > (*lst1)->next->next->order)
			b_three_132(lst1, lst2);
	    // 1 2 3
	    else
			b_three_123(lst1, lst2);
	}
}

void	b_handle_unsorted_four(t_list **lst1, t_list **lst2, int size)
{
	if (size == 2)
	{
		swap(lst1);
		push(lst1, lst2);
		push(lst1, lst2);
		return ;
	}
	else if (size == 3)
		b_three(lst1, lst2);
	else
		b_four(lst1, lst2);
}

void	b_divide_top_mid_bot(t_list **lst1, t_list **lst2, int left, int right)
{
	int	size;
	int	pivot;
    int	spivot;

	size = right - left;
	pivot = left + size / 3 + (size % 3 == 2);
    spivot = pivot + size / 3 + (size % 3 == 2);
	// printf("a left, right: %d, %d\n", left, right);
    // printf("pivot, spivot: %d, %d\n", pivot, spivot);
	while (size--)
    {
	    if ((*lst1)->order <= pivot)
	        rotate(lst1);
	    else if ((*lst1)->order <= spivot)
	    	push_rotate(lst1, lst2);
	    else
	        push(lst1, lst2);
    }
}

void    b_to_a(t_list **lst1, t_list **lst2, int left, int right)
{
	int	pivot;
	int	spivot;
	int	size;

	size = right - left;
	if (is_ordered(*lst1, 1, size))
	{
		while (size--)
			push(lst1, lst2);
		return ;
	}
	if (size <= 4)
	{
		b_handle_unsorted_four(lst1, lst2, size);
	    return ;
	}
	b_divide_top_mid_bot(lst1, lst2, left ,right);
	pivot = left + size / 3 + (size % 3 == 2);
    spivot = pivot + size / 3 + (size % 3 == 2);
	a_to_b(lst2, lst1, spivot, right);
	size = pivot - left;
    while (size--)
		reverse_rotate_both(lst1, lst2);
	a_to_b(lst2, lst1, pivot, spivot);
	b_to_a(lst1, lst2, left, pivot);
}

void	a_three(t_list **lst1, t_list **lst2)
{
	if ((*lst1)->order > (*lst1)->next->order)
    {
        // 3 2 1
        if ((*lst1)->next->order > (*lst1)->next->next->order)
            a_three_321(lst1, lst2);
        // 2 1 3
        else if ((*lst1)->next->next->order > (*lst1)->order)
            a_three_213(lst1);
        // 3 1 2
        else
			a_three_312(lst1, lst2);
    }
    else
    {
        // 2 3 1
        if ((*lst1)->order > (*lst1)->next->next->order)
			a_three_231(lst1, lst2);
        // 1 3 2
        else if ((*lst1)->next->order > (*lst1)->next->next->order)
			a_three_132(lst1, lst2);
    }
}

void	a_handle_unsorted_four(t_list **lst1, t_list **lst2, int size)
{
	if (size == 2)
		swap(lst1);
	else if (size == 3)
		a_three(lst1, lst2);
	else
		a_four(lst1, lst2);
}

void	a_divide_top_mid_bot(t_list **lst1, t_list **lst2, int left, int right)
{
	int	size;
	int	pivot;
    int	spivot;

	size = right - left;
	pivot = left + size / 3 + (size % 3 == 1);
    spivot = pivot + size / 3 + (size % 3 == 2);
	// printf("a left, right: %d, %d\n", left, right);
    // printf("pivot, spivot: %d, %d\n", pivot, spivot);
	while (size--)
    {
        if ((*lst1)->order <= pivot)
            push(lst1, lst2);
        else if ((*lst1)->order <= spivot)
			push_rotate(lst1, lst2);
        else
            rotate(lst1);
    }
	size = right - spivot;
    // printf("cnt: %d\n", cnt);
    // print_list(*lst1);
    // print_list(*lst2);
    while (size--)
		reverse_rotate_both(lst1, lst2);
}

void    a_to_b(t_list **lst1, t_list **lst2, int left, int right)
{
	int size;
	int pivot;
	int spivot;

	size = right - left;
	pivot = left + size / 3 + (size % 3 == 1);
	spivot = pivot + size / 3 + (size % 3 == 2); 
	if (is_ordered(*lst1, 0, size))
	    return ;
	if (size <= 4)
	{
		a_handle_unsorted_four(lst1, lst2, size);
	    return ;
	}
	a_divide_top_mid_bot(lst1, lst2, left, right);
	print_list(*lst1);
	print_list(*lst2);
	a_to_b(lst1, lst2, spivot, right);
	// printf("pivot, spivot: %d, %d\n", pivot, spivot);
	b_to_a(lst2, lst1, pivot, spivot);
	b_to_a(lst2, lst1, left, pivot);
	// printf("pivot, spivot: %d, %d\n", pivot, spivot);
}

void    handle_three(t_list **lst)
{
    if ((*lst)->order > (*lst)->next->order)
    {
        // 3 2 1
        if ((*lst)->next->order > (*lst)->next->next->order)
        {
            swap(lst);
            reverse_rotate(lst);
        }
        // 2 1 3
        else if ((*lst)->next->next->order > (*lst)->order)
            swap(lst);
        // 3 1 2
        else
            rotate(lst);
    }
    else
    {
        // 2 3 1
        if ((*lst)->order > (*lst)->next->next->order)
            reverse_rotate(lst);
        // 1 3 2
        else if ((*lst)->next->order > (*lst)->next->next->order)
        {
            reverse_rotate(lst);
            swap(lst);
        }
    }
}

void	push_swap(t_list **lst1)
{
	t_list	*lst2;
    int     size;

	lst2 = NULL;
    size = ft_lstsize(*lst1);
	if (!size)
		return ;
    if (size == 3)
    {
        handle_three(lst1);
        return ;
    }
    a_to_b(lst1, &lst2, 0, size);
    print_operations();
    // print_list(*lst1);
    // print_list(lst2);
	// printf("size: %d\n", size);
    if (!is_ordered(*lst1, 0, size))
		printf("List is not ordered!!!!\n");
    printf("total: %d\n", ps + sp + rt + rrt);
	ft_lstclear(lst1);
	ft_lstclear(&lst2);
	lst1 = NULL;
	lst2 = NULL;
}

int	is_high(int m, int n)
{
	return (n > m);
}

void	order_data(t_list **lst)
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
	return (0);
}