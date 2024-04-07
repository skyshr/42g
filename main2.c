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

void	push_swap(t_list **lst1, int size)
{
	t_list	*lst2;

	lst2 = NULL;
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

void	order_data(t_list **lst, int size)
{
	t_list	*cur;

	if (!size)
		return ;
	if (is_ordered(*lst, 0, size))
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

int	get_target(t_list **lst)
{
	t_list	*cur;
	int		target;

	cur = *lst;
	target = 0;
	while (cur)
	{
		target = target * 10 + cur->order;
		cur = cur->next;
	}
	return (target);
}

int	find_tens(int num)
{
	int	res;
	int	i;

	res = 1;
	while (num/10)
	{
		num /= 10;
		res *= 10;
	}
	return (res);
}

int	get_start(int size)
{
	int	res;
	int	i;

	res = 1;
	i = 2;
	while (i <= size)
		res = res * 10 + i++;
	return (res);
}

int	is_visited(int visited[240][2], int find, int to_find1, int to_find2)
{
	int	i;

	i = 0;
	while (i < find)
	{
		if (visited[i][0] == to_find1 && visited[i][1] == to_find2)
			return (1);
	}
	return (0);
}

// pa : 0, pb : 1, sa : 2, sb : 3, ss : 4, ra : 5, rb : 6, rr : 7, rra : 8, rrb : 9, rrr : a

void	bfs(t_list	**lst, int size)
{
	long long	memo[10][50][4];
	char		res[10][4];
	int			idx[10];
	int			visited[240][2];
	int			target;
	int			find;
	int			dist;

	if (!size || size >= 6)
		return ;
	target = get_target(lst);
	find = 0;
	ft_bzero(visited, sizeof(int) * 120);
	ft_bzero(idx, sizeof(int) * 10);
	idx[0]++;
	memo[0][0][0] = get_start(size);
	memo[0][0][2] = -1;
	visited[find][0] = 12345;
	visited[find][1] = 0;
	if (target)
	{
		printf("target: %lld,\n", memo[0][0][0]);
		print_list(*lst);
	}
	dist = 0;
	while (dist < 3)
	{
		int previdx = 0;
		while (previdx < idx[dist])
		{
			// stack A, stack B, prev oper, operations
			if (memo[dist][previdx][0] == target)
			{
				printf("dist: %d\n", dist);
				printf("memo[%d][%d]: %lld, %lld, %lld, %lld\n", dist, previdx, memo[dist][previdx][0], \
					memo[dist][previdx][1], memo[dist][previdx][2], memo[dist][previdx][3]);
				return ;
			}
			if (memo[dist][previdx][2] == -1)
			{
				// pb
				long long c = memo[dist][previdx][0];
				long long d = find_tens(c);
				long long e = find_tens(memo[dist][previdx][1]);
				long long f = c / d;
				long long g = c % d;
				printf("c, d, e, f, g: %lld, %lld, %lld, %lld, %lld\n", c, d, e, f, g);
				memo[dist + 1][idx[dist + 1]][0] = g;
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1] + f * e;
				memo[dist + 1][idx[dist + 1]][2] = 1;
				memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 1;
				printf("memo[%d][%d]: %lld, %lld, %lld, %lld\n", dist, previdx, memo[dist + 1][idx[dist + 1]][0], \
				memo[dist + 1][idx[dist + 1]][1], memo[dist + 1][idx[dist + 1]][2], memo[dist + 1][idx[dist + 1]][3]);
				idx[dist + 1]++;
				// sa
				long long sa = (g / (d / 10)) * d + f * (d / 10) + g % (d / 10);
				// 방문 x
				memo[dist + 1][idx[dist + 1]][0] = sa;
				if (memo[dist + 1][idx[dist + 1]][0] == target)
				{
					printf("dist: %d\n", dist + 1);
					return ;
				}
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1];
				memo[dist + 1][idx[dist + 1]][2] = 2;
				memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 2;
				printf("memo[%d][%d]: %lld, %lld, %lld, %lld\n", dist, previdx, memo[dist + 1][idx[dist + 1]][0], \
				memo[dist + 1][idx[dist + 1]][1], memo[dist + 1][idx[dist + 1]][2], memo[dist + 1][idx[dist + 1]][3]);
				idx[dist + 1]++;
				// ra
				memo[dist + 1][idx[dist + 1]][0] = g * 10 + f;
				if (memo[dist + 1][idx[dist + 1]][0] == target)
				{
					printf("dist: %d\n", dist + 1);
					return ;
				}
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1];
				memo[dist + 1][idx[dist + 1]][2] = 5;
				memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 5;
				printf("memo[%d][%d]: %lld, %lld, %lld, %lld\n", dist, previdx, memo[dist + 1][idx[dist + 1]][0], \
				memo[dist + 1][idx[dist + 1]][1], memo[dist + 1][idx[dist + 1]][2], memo[dist + 1][idx[dist + 1]][3]);
				idx[dist + 1]++;
				// rra
				memo[dist + 1][idx[dist + 1]][0] = (c % 10) * d + (c / 10);
				if (memo[dist + 1][idx[dist + 1]][0] == target)
				{
					printf("dist: %d\n", dist + 1);
					return ;
				}
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1];
				memo[dist + 1][idx[dist + 1]][2] = 8;
				memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 8;
				printf("memo[%d][%d]: %lld, %lld, %lld, %lld\n", dist, previdx, memo[dist + 1][idx[dist + 1]][0], \
				memo[dist + 1][idx[dist + 1]][1], memo[dist + 1][idx[dist + 1]][2], memo[dist + 1][idx[dist + 1]][3]);
				idx[dist + 1]++;
			}
			else
			{
				long long c = memo[dist][previdx][0];
				long long h = memo[dist][previdx][1];
				long long d = find_tens(c);
				long long e = find_tens(h);
				long long f = c / d;
				long long g = c % d;
				long long i = h / e;
				long long j = h % e;
				long long pa = 10 * d * i + c;
				long long pb = 10 * e * f + h;
				long long sa = (g / (d / 10)) * d + f * (d / 10) + g % (d / 10);
				long long sb = (j / (e / 10)) * e + i * (e / 10) + j % (e / 10);
				long long ra = 10 * g + f;
				long long rb = 10 * j + i;
				long long rra = (c % 10) * d + (c / 10);
				long long rrb = (h % 10) * e + (h / 10);
				// pa pb sa sb ss ra rb rr rra rrb rrr
				// pa
				if (!is_visited(visited, find, pa, i))
				{
					if (h)
					{
						visited[find][0] = pa;
						visited[find++][1] = i;
						memo[dist + 1][idx[dist + 1]][0] = pa;
						memo[dist + 1][idx[dist + 1]][1] = i;
						memo[dist + 1][idx[dist + 1]][2] = 0;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 0;
					}
				}
				// pb
				else if (!is_visited(visited, find, g, pb))
				{
					if (c)
					{
						visited[find][0] = g;
						visited[find++][1] = pb;
						memo[dist + 1][idx[dist + 1]][0] = g;
						memo[dist + 1][idx[dist + 1]][1] = pb;
						memo[dist + 1][idx[dist + 1]][2] = 1;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 1;
					}
				}
				// sa
				else if (!is_visited(visited, find, sa, h))
				{
					if (c > 10)
					{
						visited[find][0] = sa;
						visited[find++][1] = h;
						memo[dist + 1][idx[dist + 1]][0] = sa;
						memo[dist + 1][idx[dist + 1]][1] = h;
						memo[dist + 1][idx[dist + 1]][2] = 2;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 2;
					}
				}
				// sb
				else if (!is_visited(visited, find, c, sb))
				{
					if (h > 10)
					{
						visited[find][0] = c;
						visited[find++][1] = sb;
						memo[dist + 1][idx[dist + 1]][0] = c;
						memo[dist + 1][idx[dist + 1]][1] = sb;
						memo[dist + 1][idx[dist + 1]][2] = 3;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 3;
					}
				}
				// ss
				else if (!is_visited(visited, find, sa, sb))
				{
					if (c > 10 && h > 10)
					{
						visited[find][0] = sa;
						visited[find++][1] = sb;
						memo[dist + 1][idx[dist + 1]][0] = sa;
						memo[dist + 1][idx[dist + 1]][1] = sb;
						memo[dist + 1][idx[dist + 1]][2] = 4;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 4;
					}
				}
				// ra
				else if (!is_visited(visited, find, ra, h))
				{
					if (c > 10)
					{
						visited[find][0] = ra;
						visited[find++][1] = h;
						memo[dist + 1][idx[dist + 1]][0] = ra;
						memo[dist + 1][idx[dist + 1]][1] = h;
						memo[dist + 1][idx[dist + 1]][2] = 5;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 5;
					}
				}
				// rb
				else if (!is_visited(visited, find, c, rb))
				{
					if (h > 10)
					{
						visited[find][0] = c;
						visited[find++][1] = rb;
						memo[dist + 1][idx[dist + 1]][0] = c;
						memo[dist + 1][idx[dist + 1]][1] = rb;
						memo[dist + 1][idx[dist + 1]][2] = 6;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 6;
					}
				}
				// rr
				else if (!is_visited(visited, find, ra, rb))
				{
					if (c > 10 && h > 10)
					{
						visited[find][0] = ra;
						visited[find++][1] = rb;
						memo[dist + 1][idx[dist + 1]][0] = ra;
						memo[dist + 1][idx[dist + 1]][1] = rb;
						memo[dist + 1][idx[dist + 1]][2] = 7;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 7;
					}
				}
				// rra
				else if (!is_visited(visited, find, rra, h))
				{
					if (c > 10)
					{
						visited[find][0] = rra;
						visited[find++][1] = h;
						memo[dist + 1][idx[dist + 1]][0] = rra;
						memo[dist + 1][idx[dist + 1]][1] = h;
						memo[dist + 1][idx[dist + 1]][2] = 8;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 8;
					}
				}
				// rrb
				else if (!is_visited(visited, find, c, rrb))
				{
					if (h > 10)
					{
						visited[find][0] = c;
						visited[find++][1] = rrb;
						memo[dist + 1][idx[dist + 1]][0] = c;
						memo[dist + 1][idx[dist + 1]][1] = rrb;
						memo[dist + 1][idx[dist + 1]][2] = 9;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 9;
					}
				}
				// rrr
				else if (!is_visited(visited, find, rra, rrb))
				{
					if (c > 10 && h > 10)
					{
						visited[find][0] = rra;
						visited[find++][1] = rrb;
						memo[dist + 1][idx[dist + 1]][0] = rra;
						memo[dist + 1][idx[dist + 1]][1] = rrb;
						memo[dist + 1][idx[dist + 1]][2] = 10;
						memo[dist + 1][idx[dist + 1]][3] = memo[dist][idx[dist]][3] * 11 + 10;
					}
				}
			}
			// printf("")
			// printf("memo[%d][%d]: %d, %d, %d, %d\n", dist, previdx, memo[dist][previdx][0], \
			// memo[dist][previdx][1], memo[dist][previdx][2], memo[dist][previdx][3]);
			previdx++;
		}
		dist++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	int		size;

	lst = NULL;
	parse_data(&lst, argc, argv);
	size = ft_lstsize(lst);
	order_data(&lst, size);
	bfs(&lst, size);
	// print_list(lst);
	// push_swap(&lst);
	return (0);
}


// 123: 2
// [['sa', 'rra']]
// 132: 1
// [['rra']]
// 213: 1
// [['ra']]
// 231: 2
// [['sa', 'ra']]
// 312: 1
// [['sa']]
// 321: 0
// [[]]

// 1243: 4 -----예외
// [['pb', 'sa', 'ra', 'pa']]

// 2143: 5 ----- 예외
// [['pb', 'pb', 'ss', 'pa', 'pa']]

// 1432: 4 ----- 예외
// [['pb', 'ra', 'sa', 'pa']]

// ------
// 4321: 4
// [['sa', 'ra', 'ra', 'sa']]

// 3214: 5 
// rra sa ra ra sa
// [['sa', 'pb', 'sa', 'pa', 'sa']]

// 2143: 5 ----- 예외
// [['pb', 'pb', 'ss', 'pa', 'pa']]
//

// 1432: 4 ----- 예외
// [['pb', 'ra', 'sa', 'pa']]
// 1

// ------
// 3421: 3
// [['ra', 'ra', 'sa']]

// 4213: 2
// [['ra', 'sa']]

// 2134: 1
// [['sa']]

// 1342: 2
// [['rra', 'sa']]

// ------

// 4231: 3
// [['rra', 'sa', 'ra']]

// 2314: 4
// ra sa rra sa
// [['pb', 'sa', 'pa', 'sa']]
// 2


// 3142: 3
// [['sa', 'rra', 'sa']]

// 1423: 2
// [['sa', 'ra']]

// ------

// 2431: 4
// ra sa rra rra
// [['pb', 'sa', 'pa', 'rra']]
// 2

// 4312: 3
// [['sa', 'ra', 'ra']]

// 3124: 4
// rra sa ra ra
// [['sa', 'pb', 'sa', 'pa']]
// 1
// 1243: 4 -----예외
// [['pb', 'sa', 'ra', 'pa']]
// 1
// ------

// 3241: 2
// [['sa', 'rra']]

// 2413: 3
// [['sa', 'ra', 'sa']]

// 4132: 4
// ra ra sa rra
// [['ra', 'pb', 'sa', 'pa']]
// 1
// 1324: 3
// ra sa rra
// [['pb', 'sa', 'pa']]
// 1
// ------

// 1234 : 0

// 2341: 1
// [['rra']]

// 3412: 2
// [['ra', 'ra']]

// 4123: 1
// [['ra']]

// ------


// 123
// 213 == 1
// 321 == 2
// 132 == 2
// 312 == 1
// 231 == 1

//3432
//3212
// 1234 1243 1324 1342 1423 1432
// 0    4    3    2    2    4
// 2134 2143 2314 2341 2413 2431
// 1    5    4    1    3    4
// 3124 3142 3214 3241 3412 3421
// 4    3    5    2    2    3
// 4123 4132 4213 4231 4312 4321
// 1    4    2    3    3    4


// 12345
// 23451 51234 21345 (2345 / 1)
// (34512 x 32451) (x 45123 51234) (13452 52134 x) (3452 / 1, 5234 / 1, 3245 / 1)
// (3451 / 2) (1234 / 5) (2134 / 5) (345 / 12)






// 54321: 7 = dp(4321) + 3
// [['pb', 'sa', 'ra', 'ra', 'pa', 'ra', 'sa']]
// 45321: 6 = dp(3421) + 3
// [['rra', 'pb', 'ra', 'ra', 'sa', 'pa']]
// 53421: 6 = dp(4231) + 3
// [['pb', 'ra', 'ra', 'pa', 'ra', 'sa']]
// 35421: 5 = dp(54213) + 1 = dp(45213) + 2 = dp(52134) + 3 = dp(21345) + 4
// [['ra', 'sa', 'ra', 'ra', 'sa']]
// 43521: 4 = dp(34521) + 1 = dp(13452) + 2 = dp(21345) + 3 = dp(12345) + 4
// [['sa', 'rra', 'rra', 'sa']]
// 34521: 3 = dp(13452) + 1 = dp(21345) + 2 = dp(12345) + 3
// [['rra', 'rra', 'sa']]
// 54231: 6 = dp(4312) + 3 = dp(45231) + 1 = dp(14523) + 2 = dp(3412) + 4
// [['sa', 'rra', 'pb', 'ra', 'ra', 'pa']]
// 45231: 5
// [['rra', 'pb', 'ra', 'ra', 'pa']]
// 13425: 7
// [['pb', 'ra', 'sa', 'ra', 'ra', 'pa', 'ra']]
// 13452: 7
// [['pb', 'sa', 'ra', 'ra', 'sa', 'pa', 'sa']]
// 13524: 6
// [['ra', 'pb', 'ra', 'sa', 'pa', 'sa']]
// 13542: 6
// [['pb', 'ra', 'ra', 'sa', 'pa', 'sa']]
// 14235: 5
// [['rra', 'pb', 'ra', 'sa', 'pa']]
// 14253: 6
// [['sa', 'rra', 'pb', 'ra', 'sa', 'pa']]
// 14325: 3
// [['rra', 'sa', 'ra']]
// 14352: 4
// [['sa', 'rra', 'sa', 'ra']]
// 14523: 6
// [['pb', 'pb', 'ss', 'pa', 'pa', 'rra']]
// 14532: 5
// [['ra', 'ra', 'sa', 'ra', 'ra']]
// 15234: 6
// [['sa', 'pb', 'sa', 'pa', 'sa', 'rra']]
// 15243: 5
// [['pb', 'sa', 'pa', 'sa', 'rra']]
// 15324: 5
// [['sa', 'pb', 'sa', 'pa', 'rra']]
// 15342: 4
// [['pb', 'sa', 'pa', 'rra']]
// 15423: 2
// [['sa', 'rra']]
// 15432: 1
// [['rra']]
// 21345: 6
// [['pb', 'sa', 'ra', 'ra', 'pa', 'ra']]
// 21354: 6
// [['pb', 'sa', 'pa', 'sa', 'rra', 'rra']]
// 21435: 5
// [['pb', 'ra', 'ra', 'pa', 'ra']]
// 21453: 4
// [['ra', 'sa', 'ra', 'ra']]
// 21534: 3
// [['sa', 'rra', 'rra']]
// 21543: 2
// [['rra', 'rra']]
// 23145: 5
// [['sa', 'rra', 'rra', 'sa', 'rra']]
// 23154: 4
// [['rra', 'rra', 'sa', 'rra']]
// 23415: 7
// [['pb', 'pb', 'sa', 'rra', 'pa', 'pa', 'ra']]
// 23451: 6
// [['pb', 'sa', 'ra', 'ra', 'sa', 'pa']]
// 23514: 5
// [['ra', 'pb', 'ra', 'sa', 'pa']]
// 23541: 5
// [['pb', 'ra', 'ra', 'sa', 'pa']]
// 24135: 6
// [['pb', 'ra', 'sa', 'ra', 'pa', 'ra']]
// 24153: 6
// [['ra', 'pb', 'sa', 'ra', 'pa', 'ra']]
// 24315: 4
// [['rra', 'sa', 'ra', 'sa']]
// 24351: 5
// [['sa', 'rra', 'sa', 'ra', 'sa']]
// 24513: 6
// [['ra', 'pb', 'sa', 'ra', 'ra', 'pa']]
// 24531: 6
// [['pb', 'ra', 'sa', 'ra', 'ra', 'pa']]
// 25134: 5
// [['sa', 'ra', 'ra', 'sa', 'ra']]
// 25143: 4
// [['ra', 'ra', 'sa', 'ra']]
// 25314: 6
// [['sa', 'pb', 'sa', 'pa', 'rra', 'sa']]
// 25341: 5
// [['pb', 'sa', 'pa', 'rra', 'sa']]
// 25413: 3
// [['sa', 'rra', 'sa']]
// 25431: 2
// [['rra', 'sa']]
// 31245: 4
// [['sa', 'ra', 'ra', 'sa']]
// 31254: 3
// [['ra', 'ra', 'sa']]
// 31425: 6
// [['pb', 'sa', 'ra', 'pa', 'ra', 'sa']]
// 31452: 6
// [['pb', 'sa', 'pa', 'rra', 'sa', 'rra']]
// 31524: 4
// [['sa', 'rra', 'sa', 'rra']]
// 31542: 3
// [['rra', 'sa', 'rra']]
// 32145: 3
// [['sa', 'ra', 'ra']]
// 32154: 2
// [['ra', 'ra']]
// 32415: 5
// [['pb', 'sa', 'ra', 'pa', 'ra']]
// 32451: 5
// [['pb', 'sa', 'ra', 'ra', 'pa']]
// 32514: 3
// [['ra', 'sa', 'ra']]
// 32541: 4
// [['pb', 'ra', 'ra', 'pa']]
// 34125: 6
// [['ra', 'pb', 'pb', 'ss', 'pa', 'pa']]
// 34152: 6
// [['pb', 'ra', 'pb', 'ss', 'pa', 'pa']]
// 34215: 5
// [['rra', 'rra', 'sa', 'rra', 'rra']]
// 34251: 6
// [['pb', 'ra', 'pb', 'sa', 'pa', 'pa']]
// 34512: 6
// [['pb', 'pb', 'sa', 'rrr', 'pa', 'pa']]
// 34521: 6
// [['pb', 'pb', 'sa', 'rra', 'pa', 'pa']]
// 35124: 6
// [['ra', 'pb', 'pb', 'rr', 'pa', 'pa']]
// 35142: 6
// [['pb', 'sa', 'pb', 'rrr', 'pa', 'pa']]
// 35214: 5
// [['ra', 'pb', 'sa', 'ra', 'pa']]
// 35241: 5
// [['pb', 'ra', 'sa', 'ra', 'pa']]
// 35412: 5
// [['pb', 'pb', 'rrr', 'pa', 'pa']]
// 35421: 5
// [['pb', 'pb', 'rra', 'pa', 'pa']]
// 41235: 6
// [['sa', 'rra', 'sa', 'rra', 'rra', 'sa']]
// 41253: 5
// [['rra', 'sa', 'rra', 'rra', 'sa']]
// 41325: 5
// [['ra', 'pb', 'sa', 'pa', 'sa']]
// 41352: 5
// [['pb', 'ra', 'sa', 'pa', 'sa']]
// 41523: 6
// [['pb', 'pb', 'rrr', 'pa', 'pa', 'rra']]
// 41532: 6
// [['pb', 'pb', 'rra', 'pa', 'pa', 'rra']]
// 42135: 5
// [['sa', 'rra', 'sa', 'rra', 'rra']]
// 42153: 4
// [['rra', 'sa', 'rra', 'rra']]
// 42315: 4
// [['ra', 'pb', 'sa', 'pa']]
// 42351: 4
// [['pb', 'ra', 'sa', 'pa']]
// 42513: 6
// [['pb', 'pb', 'rr', 'pa', 'sa', 'pa']]
// 42531: 5
// [['pb', 'sa', 'ra', 'sa', 'pa']]
// 43125: 2
// [['ra', 'sa']]
// 43152: 3
// [['sa', 'ra', 'sa']]
// 43215: 1
// [['ra']]
// 43251: 2
// [['sa', 'ra']]
// 43512: 5
// [['pb', 'pb', 'rr', 'pa', 'pa']]
// 43521: 4
// [['pb', 'sa', 'ra', 'pa']]
// 45123: 7
// [['pb', 'pb', 'sa', 'rrr', 'pa', 'pa', 'rra']]
// 45132: 7
// [['pb', 'pb', 'pb', 'rr', 'pa', 'pa', 'pa']]
// 45213: 7
// [['pb', 'pb', 'pb', 'rrr', 'pa', 'pa', 'pa']]
// 45231: 7
// [['pb', 'pb', 'pb', 'ss', 'pa', 'pa', 'pa']]
// 45312: 6
// [['pb', 'pb', 'sa', 'rr', 'pa', 'pa']]
// 45321: 5
// [['rra', 'rra', 'sa', 'ra', 'ra']]
// 51234: 8
// [['pb', 'pb', 'sa', 'rrr', 'pa', 'pa', 'rra', 'rra']]
// 51243: 7
// [['ra', 'ra', 'pb', 'pb', 'rr', 'pa', 'pa']]
// 51324: 7
// [['pb', 'ra', 'ra', 'pa', 'ra', 'sa', 'ra']]
// 51342: 6
// [['ra', 'sa', 'ra', 'ra', 'sa', 'ra']]
// 51423: 5
// [['sa', 'rra', 'rra', 'sa', 'ra']]
// 51432: 4
// [['rra', 'rra', 'sa', 'ra']]
// 52134: 7
// [['pb', 'pb', 'rrr', 'pa', 'pa', 'rra', 'rra']]
// 52143: 6
// [['ra', 'ra', 'pb', 'sa', 'ra', 'pa']]
// 52314: 6
// [['rra', 'sa', 'rra', 'rra', 'sa', 'rra']]
// 52341: 7
// [['pb', 'sa', 'pb', 'sa', 'pa', 'sa', 'pa']]
// 52413: 6
// [['pb', 'pb', 'ss', 'pa', 'sa', 'pa']]
// 52431: 5
// [['rra', 'rra', 'sa', 'ra', 'sa']]
// 53124: 5
// [['rra', 'sa', 'ra', 'ra', 'sa']]
// 53142: 6
// [['pb', 'sa', 'pb', 'ss', 'pa', 'pa']]
// 53214: 4
// [['rra', 'sa', 'ra', 'ra']]
// 53241: 5
// [['sa', 'rra', 'sa', 'ra', 'ra']]
// 53412: 5
// [['pb', 'pb', 'ss', 'pa', 'pa']]
// 53421: 5
// [['pb', 'pb', 'sa', 'pa', 'pa']]
// 54123: 5
// [['sa', 'pb', 'sa', 'pa', 'sa']]
// 54132: 4
// [['pb', 'sa', 'pa', 'sa']]
// 54213: 4
// [['sa', 'pb', 'sa', 'pa']]
// 54231: 3
// [['pb', 'sa', 'pa']]
// 54312: 1
// [['sa']]
// 54321: 0
// [[]]