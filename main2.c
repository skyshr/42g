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
		// printf("Only digits are allowed!, %d\n", **argv);
		printf("Error\n");
		return (0);
	}
	while (ft_isdigit(**argv))
	{
		n = n * 10 + **argv - '0';
		if (n > (unsigned int)(2147483647 + (sign == -1)))
		{
			printf("Error\n");
			// printf("Overflow detected!\n");
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
			printf("Error\n");
			// printf("Error detected!\n");
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

void	push(t_list **lst1, t_list **lst2, int sign)
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
	if (!sign)
		printf("pb\n");
	else
		printf("pa\n");
	// printf("p\n");
	ps++;
}

void	swap(t_list **lst, int sign)
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
	if (!sign)
		printf("sa\n");
	else if (sign == 1)
		printf("sb\n");
	// printf("s\n");
	sp++;
}

void	rotate(t_list **lst, int sign)
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
	if (!sign)
		printf("ra\n");
	else if (sign == 1)
		printf("rb\n");
	// printf("rt\n");
	rt++;
}

void	reverse_rotate(t_list **lst, int sign)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	if (!tmp || !(*lst)->next)
		return ;
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(lst, tmp);
	if (!sign)
		printf("rra\n");
	else if (sign == 1)
		printf("rrb\n");
	// printf("rrt\n");
	rrt++;
}

void	swap_both(t_list **lst1, t_list **lst2)
{
	swap(lst1, 2);
	swap(lst2, 2);
	printf("ss\n");
	sp--;
}

void	rotate_both(t_list **lst1, t_list **lst2)
{
	rotate(lst1, 2);
	rotate(lst2, 2);
	printf("rr\n");
	rt--;
}

void	reverse_rotate_both(t_list **lst1, t_list **lst2)
{
	reverse_rotate(lst1, 2);
	reverse_rotate(lst2, 2);
	printf("rrr\n");
	rrt--;
}

void	push_rotate(t_list **lst1, t_list **lst2, int sign)
{
	push(lst1, lst2, sign);
	rotate(lst2, sign);
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
	push(lst1, lst2, 0);
	a_three_231(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, 0);
}

void	a_four_1243(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_132(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_1342(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_231(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_1324(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_213(lst1);
	push(lst2, lst1, 1);
}

void	a_four_1423(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_312(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_1432(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_321(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_2431(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_321(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, 0);
}

void	a_four_2314(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	a_three_213(lst1);
	push(lst2, lst1, 1);
	swap(lst1, 0);
}

void	a_four_2413(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	push(lst2, lst1, 1);
}

void	a_four_3412(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, 0);
	push(lst2, lst1, 1);
}

void	a_four_3421(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, 0);
	push(lst2, lst1, 1);
	swap(lst1, 0);
}

void	a_four_3214(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	a_three_213(lst1);
	push(lst2, lst1, 1);
	swap(lst1, 0);
}

void	a_four_4321(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, 0);
	push(lst2, lst1, 1);
	swap(lst1, 0);
}

void	a_four_4312(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, 0);
	push(lst2, lst1, 1);
}

void	a_four_4213(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap(lst1, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	push(lst2, lst1, 1);
}

void	a_four_2134(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
}

void	a_four_2143(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	push(lst2, lst1, 1);
}

void	a_four_3142(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	push(lst2, lst1, 1);
	swap(lst1, 0);
	push(lst2, lst1, 1);
}

void	a_four_3241(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	rotate(lst1, 0);
	push(lst2, lst1, 1);
	push(lst2, lst1, 1);
	reverse_rotate(lst1, 0);
}

void	a_four_3124(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	a_three_213(lst1);
	push(lst2, lst1, 1);
}

void	a_four_4123(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	a_three_312(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_4132(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	push(lst1, lst2, 0);
	a_three_321(lst1, lst2);
	push(lst2, lst1, 1);
}

void	a_four_4231(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	push(lst1, lst2, 0);
	swap_both(lst1, lst2);
	rotate(lst1, 0);
	push(lst2, lst1, 1);
	swap(lst1, 0);
	push(lst2, lst1, 1);
	reverse_rotate(lst1, 0);
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
	push(lst1, lst2, 1);
	rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	reverse_rotate(lst1, 1);
	push(lst1, lst2, 1);
	reverse_rotate(lst2, 0);
}

void	b_four_1243(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	reverse_rotate(lst1, 1);
	push(lst1, lst2, 1);
	reverse_rotate(lst2, 0);
}

void	b_four_1324(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate(lst2, 0);
	b_three_213(lst1, lst2);
	reverse_rotate(lst2, 0);
}

void	b_four_1342(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate(lst2, 0);
	b_three_231(lst1, lst2);
	reverse_rotate(lst2, 0);
}

void	b_four_1423(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate(lst2, 0);
	b_three_312(lst1, lst2);
	reverse_rotate(lst2, 0);
}

void	b_four_1432(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate(lst2, 0);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	reverse_rotate(lst2, 0);
}

void	b_four_2134(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	reverse_rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
}

void	b_four_2143(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	reverse_rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
}

void	b_four_2314(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	reverse_rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
}

void	b_four_2341(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	swap(lst1, 1);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	push(lst1, lst2, 1);
}

void	b_four_2413(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap_both(lst1, lst2);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	push(lst1, lst2, 1);
}

void	b_four_2431(t_list **lst1, t_list **lst2)
{
	swap(lst1, 1);
	push(lst1, lst2, 1);
	swap(lst1, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_four_3124(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	rotate(lst1, 1);
	swap(lst1, 1);
	push(lst1, lst2, 1);
	reverse_rotate(lst1, 1);
	swap_both(lst1, lst2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_four_3142(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	swap(lst1, 1);
	push(lst1, lst2, 1);
	swap_both(lst1, lst2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_four_3214(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	reverse_rotate_both(lst1, lst2);
	push(lst1, lst2, 1);
}

void	b_four_3241(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	swap(lst1, 1);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_four_3412(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap_both(lst1, lst2);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_four_3421(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	swap(lst2, 0);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void	b_four_4123(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	b_three_123(lst1, lst2);
}

void	b_four_4132(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	b_three_132(lst1, lst2);
}

void	b_four_4213(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	b_three_213(lst1, lst2);
}

void	b_four_4231(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	b_three_231(lst1, lst2);
}

void	b_four_4312(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	b_three_312(lst1, lst2);
}

void    a_three_132(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 0);
	swap(lst1, 0);
	push(lst2, lst1, 0);
}

void    a_three_213(t_list **lst)
{
	swap(lst, 0);
}

void    a_three_231(t_list **lst1, t_list **lst2)
{
	a_three_132(lst1, lst2);
	swap(lst1, 0);
}

void    a_three_312(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	a_three_132(lst1, lst2);
}

void    a_three_321(t_list **lst1, t_list **lst2)
{
	swap(lst1, 0);
	a_three_231(lst1, lst2);
}

void    b_two(t_list **lst1, t_list **lst2)
{
    swap(lst1, 1);
    push(lst1, lst2, 1);
    push(lst1, lst2, 1);
}

void    b_three_123(t_list **lst1, t_list **lst2)
{
	swap(lst1, 1);
	b_three_213(lst1, lst2);
}

void    b_three_132(t_list **lst1, t_list **lst2)
{
	swap(lst1, 1);
	b_three_312(lst1, lst2);
}

void    b_three_213(t_list **lst1, t_list **lst2)
{
    push(lst1, lst2, 1);
    swap(lst1, 1);
    push(lst1, lst2, 1);
    swap(lst2, 0);
    push(lst1, lst2, 1);
}

void    b_three_231(t_list **lst1, t_list **lst2)
{
	swap(lst1, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
}

void    b_three_312(t_list **lst1, t_list **lst2)
{
	push(lst1, lst2, 1);
	swap(lst1, 1);
	push(lst1, lst2, 1);
	push(lst1, lst2, 1);
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
		swap(lst1, 1);
		push(lst1, lst2, 1);
		push(lst1, lst2, 1);
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
	while (size--)
    {
	    if ((*lst1)->order <= pivot)
	        rotate(lst1, 1);
	    else if ((*lst1)->order <= spivot)
	    	push_rotate(lst1, lst2, 1);
	    else
	        push(lst1, lst2, 1);
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
			push(lst1, lst2, 1);
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
		swap(lst1, 0);
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
	while (size--)
    {
        if ((*lst1)->order <= pivot)
            push(lst1, lst2, 0);
        else if ((*lst1)->order <= spivot)
			push_rotate(lst1, lst2, 0);
        else
            rotate(lst1, 0);
    }
	size = right - spivot;
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
	a_to_b(lst1, lst2, spivot, right);
	b_to_a(lst2, lst1, pivot, spivot);
	b_to_a(lst2, lst1, left, pivot);
}

void    handle_three(t_list **lst)
{
    if ((*lst)->order > (*lst)->next->order)
    {
        // 3 2 1
        if ((*lst)->next->order > (*lst)->next->next->order)
        {
            swap(lst, 0);
            reverse_rotate(lst, 0);
        }
        // 2 1 3
        else if ((*lst)->next->next->order > (*lst)->order)
            swap(lst, 0);
        // 3 1 2
        else
            rotate(lst, 0);
    }
    else
    {
        // 2 3 1
        if ((*lst)->order > (*lst)->next->next->order)
            reverse_rotate(lst, 0);
        // 1 3 2
        else if ((*lst)->next->order > (*lst)->next->next->order)
        {
            reverse_rotate(lst, 0);
            swap(lst, 0);
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
    if (!is_ordered(*lst1, 0, size))
		printf("List is not ordered!!!!\n");
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

unsigned long long	find_tens(unsigned long long num)
{
	unsigned long long	res;

	res = 1;
	while (num / 10)
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

int	is_visited(int visited[1800][2], int find, int to_find1, int to_find2)
{
	int	i;

	i = 0;
	if (to_find2 >= 100)
		return (1);
	while (i < find)
	{
		if (visited[i][0] == to_find1 && visited[i][1] == to_find2)
			return (1);
		i++;
	}
	return (0);
}

void	print_answer(t_list **lst1, int dist, unsigned long long n)
{
	t_list	*lst2;
	int		m;
	int		tmp;

	lst2 = NULL;
	tmp = dist;
	while (dist--)
	{
		m = n % 11;
		if (m == 0)
			push(lst1, &lst2, 0);
		else if (m == 1)
			push(&lst2, lst1, 1);
		else if (m == 2)
			swap(lst1, 0);
		else if (m == 3)
			swap(&lst2, 1);
		else if (m == 4)
			swap_both(lst1, &lst2);
		else if (m == 5)
			reverse_rotate(lst1, 0);
		else if (m == 6)
			reverse_rotate(&lst2, 1);
		else if (m == 7)
			reverse_rotate_both(lst1, &lst2);
		else if (m == 8)
			rotate(lst1, 0);
		else if (m == 9)
			rotate(&lst2, 1);
		else
			rotate_both(lst1, &lst2);
		n /= 11;
	}
	lst2 = NULL;
}

void	bfs(t_list	**lst, int size)
{
	unsigned long long	memo[10][480][3];
	char				res[10][4];
	int					idx[10];
	int					visited[1800][2];
	int					target;
	int					find;
	int					dist;

	if (!size || size >= 6)
		return ;
	target = get_target(lst);
	find = 0;
	ft_bzero(visited, sizeof(int) * 120);
	ft_bzero(idx, sizeof(int) * 10);
	idx[0]++;
	memo[0][0][0] = get_start(size);
	memo[0][0][2] = 0;
	visited[find][0] = 12345;
	visited[find][1] = 0;
	dist = 0;
	while (1)
	{
		int previdx = 0;
		while (previdx < idx[dist])
		{
			if (memo[dist][previdx][0] == target)
			{
				print_answer(lst, dist, memo[dist][previdx][2]);
				return ;
			}
			if (dist == 0)
			{
				long long c = memo[dist][previdx][0];
				long long d = find_tens(c);
				long long e = find_tens(memo[dist][previdx][1]);
				long long f = c / d;
				long long g = c % d;
				long long h = memo[dist][previdx][1];
				long long pb = h + f * e;
				long long sa = (g / (d / 10)) * d + f * (d / 10) + g % (d / 10);
				long long ra = 10 * g + f;
				long long rra = (c % 10) * d + (c / 10);
				// pb
				visited[find][0] = g;
				visited[find++][1] = pb;
				memo[dist + 1][idx[dist + 1]][0] = g;
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1] + f * e;
				memo[dist + 1][idx[dist + 1]][2] = memo[dist][idx[dist]][2] * 11 + 1;
				idx[dist + 1]++;
				// sa
				visited[find][0] = sa;
				visited[find++][1] = h;
				memo[dist + 1][idx[dist + 1]][0] = sa;
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1];
				memo[dist + 1][idx[dist + 1]][2] = memo[dist][idx[dist]][2] * 11 + 2;
				idx[dist + 1]++;
				// ra
				visited[find][0] = ra;
				visited[find++][1] = h;
				memo[dist + 1][idx[dist + 1]][0] = g * 10 + f;
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1];
				memo[dist + 1][idx[dist + 1]][2] = memo[dist][idx[dist]][2] * 11 + 5;
				idx[dist + 1]++;
				// rra
				visited[find][0] = rra;
				visited[find++][1] = h;
				memo[dist + 1][idx[dist + 1]][0] = rra;
				memo[dist + 1][idx[dist + 1]][1] = memo[dist][previdx][1];
				memo[dist + 1][idx[dist + 1]][2] = memo[dist][idx[dist]][2] * 11 + 8;
				idx[dist + 1]++;
			}
			else
			{
				unsigned long long c = memo[dist][previdx][0];
				unsigned long long h = memo[dist][previdx][1];
				unsigned long long d = find_tens(c);
				unsigned long long e = find_tens(h);
				unsigned long long f = c / d;
				unsigned long long g = c % d;
				unsigned long long i = h / e;
				unsigned long long j = h % e;
				unsigned long long pa; 
				unsigned long long pb;
				unsigned long long sa;
				unsigned long long sb;
				unsigned long long ra = 10 * g + f;
				unsigned long long rb = 10 * j + i;
				unsigned long long rra;
				unsigned long long rrb;
				if (h)
					pa = 10 * d * i + c;
				else
					pa = c;
				if (h)
					pb = 10 * e * f + h;
				else
					pb = f;
				if (c > 10)
					sa = (g / (d / 10)) * d + f * (d / 10) + g % (d / 10);
				else 
					sa = c;
				if (h > 10)
					sb = (j / (e / 10)) * e + i * (e / 10) + j % (e / 10);
				else
					sb = h;
				if (c)
					rra = (c % 10) * d + (c / 10);
				else
					rra = c;
				if (h)
					rrb = (h % 10) * e + (h / 10);
				else
					rrb = h;
				if (!is_visited(visited, find, pa, j))
				{
					if (h)
					{
						visited[find][0] = pa;
						visited[find++][1] = j;
						memo[dist + 1][idx[dist + 1]][0] = pa;
						memo[dist + 1][idx[dist + 1]][1] = j;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 0;
						idx[dist + 1]++;
					}
				}
				// pb
				if (!is_visited(visited, find, g, pb))
				{
					if (c)
					{
						visited[find][0] = g;
						visited[find++][1] = pb;
						memo[dist + 1][idx[dist + 1]][0] = g;
						memo[dist + 1][idx[dist + 1]][1] = pb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 1;
						idx[dist + 1]++;
					}
				}
				// sa
				if (!is_visited(visited, find, sa, h))
				{
					if (c > 10)
					{
						visited[find][0] = sa;
						visited[find++][1] = h;
						memo[dist + 1][idx[dist + 1]][0] = sa;
						memo[dist + 1][idx[dist + 1]][1] = h;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 2;
						idx[dist + 1]++;
					}
				}
				// sb
				if (!is_visited(visited, find, c, sb))
				{
					if (h > 10)
					{
						visited[find][0] = c;
						visited[find++][1] = sb;
						memo[dist + 1][idx[dist + 1]][0] = c;
						memo[dist + 1][idx[dist + 1]][1] = sb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 3;
						idx[dist + 1]++;
					}
				}
				// ss
				if (!is_visited(visited, find, sa, sb))
				{
					if (c > 10 && h > 10)
					{
						visited[find][0] = sa;
						visited[find++][1] = sb;
						memo[dist + 1][idx[dist + 1]][0] = sa;
						memo[dist + 1][idx[dist + 1]][1] = sb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 4;
						idx[dist + 1]++;
					}
				}
				// ra
				if (!is_visited(visited, find, ra, h))
				{
					if (c > 10)
					{
						visited[find][0] = ra;
						visited[find++][1] = h;
						memo[dist + 1][idx[dist + 1]][0] = ra;
						memo[dist + 1][idx[dist + 1]][1] = h;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 5;
						idx[dist + 1]++;
					}
				}
				// rb
				if (!is_visited(visited, find, c, rb))
				{
					if (h > 10)
					{
						visited[find][0] = c;
						visited[find++][1] = rb;
						memo[dist + 1][idx[dist + 1]][0] = c;
						memo[dist + 1][idx[dist + 1]][1] = rb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 6;
						idx[dist + 1]++;
					}
				}
				// rr
				if (!is_visited(visited, find, ra, rb))
				{
					if (c > 10 && h > 10)
					{
						visited[find][0] = ra;
						visited[find++][1] = rb;
						memo[dist + 1][idx[dist + 1]][0] = ra;
						memo[dist + 1][idx[dist + 1]][1] = rb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 7;
						idx[dist + 1]++;
					}
				}
				// rra
				if (!is_visited(visited, find, rra, h))
				{
					if (c > 10)
					{
						visited[find][0] = rra;
						visited[find++][1] = h;
						memo[dist + 1][idx[dist + 1]][0] = rra;
						memo[dist + 1][idx[dist + 1]][1] = h;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 8;
						idx[dist + 1]++;
					}
				}
				// rrb
				if (!is_visited(visited, find, c, rrb))
				{
					if (h > 10)
					{
						visited[find][0] = c;
						visited[find++][1] = rrb;
						memo[dist + 1][idx[dist + 1]][0] = c;
						memo[dist + 1][idx[dist + 1]][1] = rrb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 9;
						idx[dist + 1]++;
					}
				}
				// rrr
				if (!is_visited(visited, find, rra, rrb))
				{
					if (c > 10 && h > 10)
					{
						visited[find][0] = rra;
						visited[find++][1] = rrb;
						memo[dist + 1][idx[dist + 1]][0] = rra;
						memo[dist + 1][idx[dist + 1]][1] = rrb;
						memo[dist + 1][idx[dist + 1]][2] = memo[dist][previdx][2] * 11 + 10;
						idx[dist + 1]++;
					}
				}
			}
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
	push_swap(&lst, size);
	return (0);
}

// pa : 0, pb : 1, sa : 2, sb : 3, ss : 4, ra : 5, rb : 6, rr : 7, rra : 8, rrb : 9, rrr : a