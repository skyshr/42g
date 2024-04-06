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

void    a_four(t_list **lst1, t_list **lst2)
{
	printf("-------------------------before--------------------------------\n");
	printf("%d, %d, %d, %d\n", (*lst1)->order, (*lst1)->next->order, (*lst1)->next->next->order, (*lst1)->next->next->next->order);
    if ((*lst1)->order < (*lst1)->next->order)
    {
        if ((*lst1)->next->order < (*lst1)->next->next->order)
        {
            // 2 3 4 1
            if ((*lst1)->next->next->next->order < (*lst1)->order)
            {
				push(lst1, lst2);
				a_three_231(lst1, lst2);
				push(lst2, lst1);
				swap(lst1);
				printf("2341\n");
            }
			// 1 2 4 3
			else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
			{
				push(lst1, lst2);
				a_three_132(lst1, lst2);
				push(lst2, lst1);
				printf("1243\n");
			}
			// 1 3 4 2
			else
			{
				push(lst1, lst2);
				a_three_231(lst1, lst2);
				push(lst2, lst1);
				printf("1342\n");
			}
        }
		else if ((*lst1)->order < (*lst1)->next->next->order)
		{
			// 1 3 2 4
			if ((*lst1)->next->next->next->order > (*lst1)->next->order)
			{
				push(lst1, lst2);
				a_three_213(lst1);
				push(lst2, lst1);
				printf("1324\n");
			}
			// 1 4 2 3
			else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
			{
				push(lst1, lst2);
				a_three_312(lst1, lst2);
				push(lst2, lst1);
				printf("1423\n");
			}
			// 1 4 3 2
			else if ((*lst1)->next->next->next->order > (*lst1)->order)
			{
				push(lst1, lst2);
				a_three_321(lst1, lst2);
				push(lst2, lst1);
				printf("1432\n");
			}
			// 2 4 3 1
			else
			{
				push(lst1, lst2);
				a_three_321(lst1, lst2);
				push(lst2, lst1);
				swap(lst1);
				printf("2431\n");
			}
		}
		else 
		{
			// 2 3 1 4
			if ((*lst1)->next->next->next->order > (*lst1)->next->order)
			{
				push(lst1, lst2);
				a_three_213(lst1);
				push(lst2, lst1);
				swap(lst1);
				printf("2314\n");
			}
			// 2 4 1 3
			else if ((*lst1)->next->next->next->order > (*lst1)->order)
			{
				push(lst1, lst2);
				a_three_312(lst1, lst2);
				push(lst2, lst1);
				swap(lst1);
				printf("2413\n");
			}
			// 3 4 1 2
			else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
			{
				push(lst1, lst2);
				swap(lst1);
				push(lst1, lst2);
				swap_both(lst1, lst2);
				push(lst2, lst1);
				swap(lst1);
				push(lst2, lst1);
				printf("3412\n");
			}
			// 3 4 2 1
			else
			{
				push(lst1, lst2);
				swap(lst1);
				push(lst1, lst2);
				swap_both(lst1, lst2);
				push(lst2, lst1);
				swap(lst1);
				push(lst2, lst1);
				swap(lst1);
				printf("3421\n");
			}
		}
    }
	else
	{
		if ((*lst1)->next->order > (*lst1)->next->next->order)
		{
			// 3 2 1 4
			if ((*lst1)->next->next->next->order > (*lst1)->order)
			{
				swap(lst1);
				push(lst1, lst2);
				a_three_213(lst1);
				push(lst2, lst1);
				swap(lst1);
				printf("3214\n");
			}
			// 4 3 2 1
			else if ((*lst1)->next->next->next->order < (*lst1)->next->next->order)
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
				printf("4321\n");
			}
			// 4 3 1 2
			else if ((*lst1)->next->next->next->order < (*lst1)->next->order)
			{
				swap(lst1);
				push(lst1, lst2);
				swap(lst1);
				push(lst1, lst2);
				swap_both(lst1, lst2);
				push(lst2, lst1);
				swap(lst1);
				push(lst2, lst1);
				printf("4312\n");
			}
			// 4 2 1 3
			else
			{
				swap(lst1);
				push(lst1, lst2);
				swap(lst1);
				push(lst1, lst2);
				swap_both(lst1, lst2);
				push(lst2, lst1);
				push(lst2, lst1);
				printf("4213\n");
			}
		}
		else if ((*lst1)->order < (*lst1)->next->next->order)
		{
			// 2 1 3 4
			if ((*lst1)->next->next->order < (*lst1)->next->next->next->order)
			{
				swap(lst1);
				printf("2134\n");	
			}
			// 2 1 4 3
			else if ((*lst1)->next->next->next->order > (*lst1)->order)
			{
				swap(lst1);
				push(lst1, lst2);
				a_three_132(lst1, lst2);
				push(lst2, lst1);
				printf("2143\n");
			}
			// 3 1 4 2
			else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
			{
				swap(lst1);
				push(lst1, lst2);
				a_three_231(lst1, lst2);
				push(lst2, lst1);
				printf("3142\n");
			}
			// 3 2 4 1
			else
			{
				swap(lst1);
				push(lst1, lst2);
				a_three_231(lst1, lst2);
				push(lst2, lst1);
				swap(lst1);
				printf("3241\n");
			}
		}
		else
		{
			// 3 1 2 4
			if ((*lst1)->order < (*lst1)->next->next->next->order)
			{
				swap(lst1);
				push(lst1, lst2);
				a_three_213(lst1);
				push(lst2, lst1);
				printf("3124\n");
			}
			// 4 1 2 3
			else if ((*lst1)->next->next->next->order > (*lst1)->next->next->order)
			{
				swap(lst1);
				push(lst1, lst2);
				a_three_312(lst1, lst2);
				push(lst2, lst1);
				printf("4123\n");
			}
			// 4 1 3 2
			else if ((*lst1)->next->next->next->order > (*lst1)->next->order)
			{
				swap(lst1);
				push(lst1, lst2);
				a_three_321(lst1, lst2);
				push(lst2, lst1);
				printf("4132\n");
			}
			// 4 2 3 1
			else
			{
				swap(lst1);
				push(lst1, lst2);
				a_three_321(lst1, lst2);
				push(lst2, lst1);
				swap(lst1);
				printf("4231\n");
			}
		}
	}
	printf("%d, %d, %d, %d\n", (*lst1)->order, (*lst1)->next->order, (*lst1)->next->next->order, (*lst1)->next->next->next->order);
	printf("\n----------------------------------------\n");
}

void	b_four_1234(t_list **lst1, t_list **lst2)
{
	//pa pa ss ra ra pa pa rra rra - 9
	push(lst1, lst2);
	rotate(lst2);
	b_three_123(lst1, lst2);
	reverse_rotate(lst2);
}

void	b_four_1243(t_list **lst1, t_list **lst2)
{
	// sb pa sb pa ss pa sa pa - 8
	push(lst1, lst2);
	rotate(lst2);
	b_three_132(lst1, lst2);
	reverse_rotate(lst2);
}

void	b_four_1324(t_list **lst1, t_list **lst2)
{
	// 8
	push(lst1, lst2);
	rotate(lst2);
	b_three_213(lst1, lst2);
	reverse_rotate(lst2);
}

void	b_four_1342(t_list **lst1, t_list **lst2)
{
	// 7
	push(lst1, lst2);
	rotate(lst2);
	b_three_231(lst1, lst2);
	reverse_rotate(lst2);
}

void	b_four_1423(t_list **lst1, t_list **lst2)
{
	// 7
	push(lst1, lst2);
	rotate(lst2);
	b_three_312(lst1, lst2);
	reverse_rotate(lst2);
}

void	b_four_1432(t_list **lst1, t_list **lst2)
{
	// 6
	push(lst1, lst2);
	rotate(lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
	reverse_rotate(lst2);
}

void	b_four_2134(t_list **lst1, t_list **lst2)
{
	// pa sb ra pa sb pa sa rra pa
	// 9
	rotate(lst1);
	rotate(lst1);
	push(lst1, lst2);
	push(lst1, lst2);
	swap(lst2);
	reverse_rotate(lst1);
	reverse_rotate(lst1);
	push(lst1, lst2);
	push(lst1, lst2);
}

void	b_four_2143(t_list **lst1, t_list **lst2)
{
	// 8
	rotate(lst1);
	rotate(lst1);
	push(lst1, lst2);
	push(lst1, lst2);
	reverse_rotate(lst1);
	reverse_rotate(lst1);
	push(lst1, lst2);
	push(lst1, lst2);
}

void	b_four_2314(t_list **lst1, t_list **lst2)
{
	// pa pa ss ra pa sa rra pa
	// 8
	push(lst1, lst2);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	rotate(lst1);
	push(lst1, lst2);
	swap(lst2);
	reverse_rotate(lst1);
	push(lst1, lst2);
}

void	b_four_2341(t_list **lst1, t_list **lst2)
{
	// sb pa sb pa sa pa pa - 7
	swap(lst1);
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap(lst2);
	push(lst1, lst2);
	push(lst1, lst2);
}

void	b_four_2413(t_list **lst1, t_list **lst2)
{
	// pa pa ss pa sa pa - 6
	push(lst1, lst2);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst1, lst2);
	swap(lst2);
	push(lst1, lst2);
}

void	b_four_2431(t_list **lst1, t_list **lst2)
{
	// 6
	swap(lst1);
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
}

void	b_four_3124(t_list **lst1, t_list **lst2)
{
	// pa pa sb pa sa ra sa pa rra
	// pa rb rb pa rrb rrb ss pa pa
	// pa rb sb pa rrb ss pa pa - 8
	push(lst1, lst2);
	rotate(lst1);
	swap(lst1);
	push(lst1, lst2);
	reverse_rotate(lst1);
	swap_both(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
}

void	b_four_3142(t_list **lst1, t_list **lst2)
{
	// 6
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
}

void	b_four_3214(t_list **lst1, t_list **lst2)
{
	// pa pa sb ra pa sa rra pa - 8
	push(lst1, lst2);
	push(lst1, lst2);
	swap(lst1);
	rotate(lst1);
	push(lst1, lst2);
	swap(lst2);
	reverse_rotate(lst2);
	push(lst1, lst2);
}

void	b_four_3241(t_list **lst1, t_list **lst2)
{
	// pa sb pa sa pa pa - 6
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	swap(lst2);
	push(lst1, lst2);
	push(lst1, lst2);
}

void	b_four_3412(t_list **lst1, t_list **lst2)
{
	// 5
	push(lst1, lst2);
	push(lst1, lst2);
	swap_both(lst1, lst2);
	push(lst1, lst2);
	push(lst1, lst2);
}

void	b_four_3421(t_list **lst1, t_list **lst2)
{
	// 5
	push(lst1, lst2);
	push(lst1, lst2);
	swap(lst1);
	push(lst1, lst2);
	push(lst1, lst2);
}

void	b_four_4123(t_list **lst1, t_list **lst2)
{
	// 7
	push(lst1, lst2);
	b_three_123(lst1, lst2);
}

void	b_four_4132(t_list **lst1, t_list **lst2)
{
	// 6
	push(lst1, lst2);
	b_three_132(lst1, lst2);
}

void	b_four_4213(t_list **lst1, t_list **lst2)
{
	// 6
	push(lst1, lst2);
	b_three_213(lst1, lst2);
}

void	b_four_4231(t_list **lst1, t_list **lst2)
{
	// 5
	push(lst1, lst2);
	b_three_231(lst1, lst2);
}

void	b_four_4312(t_list **lst1, t_list **lst2)
{
	// 5
	push(lst1, lst2);
	b_three_312(lst1, lst2);
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

void	b_handle_unsorted_three(t_list **lst1, t_list **lst2, int size)
{
	if (size == 2)
	{
		swap(lst1);
		push(lst1, lst2);
		push(lst1, lst2);
		return ;
	}
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
	// printf("BBBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
	// print_list(*lst1);
	// printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	// print_list(*lst2);
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
	if (size <= 3)
	{
		b_handle_unsorted_three(lst1, lst2, size);
	    return ;
	}
	b_divide_top_mid_bot(lst1, lst2, left ,right);
	pivot = left + size / 3 + (size % 3 == 2);
    spivot = pivot + size / 3 + (size % 3 == 2);
	// printf("B---------------------\n");
	// print_list(*lst1);
	// print_list(*lst2);
	a_to_b(lst2, lst1, spivot, right);
	size = pivot - left;
    while (size--)
		reverse_rotate_both(lst1, lst2);
	a_to_b(lst2, lst1, pivot, spivot);
	b_to_a(lst1, lst2, left, pivot);
	// printf("pivot, spivot: %d, %d\n", pivot, spivot);
}

void	a_handle_unsorted_three(t_list **lst1, t_list **lst2, int size)
{
	if (size == 2)
	{
		swap(lst1);
		return ;
	}
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
	// printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	// print_list(*lst1);
}

void	a_divide_top_mid_bot(t_list **lst1, t_list **lst2, int left, int right)
{
	int	size;
	int	pivot;
    int	spivot;

	size = right - left;
	pivot = left + size / 3 + (size % 3 == 1);
    spivot = pivot + size / 3 + (size % 3 == 2);
	printf("a left, right: %d, %d\n", left, right);
    printf("pivot, spivot: %d, %d\n", pivot, spivot);
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
    print_list(*lst1);
    print_list(*lst2);
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
	if (size <= 3)
	{
		a_handle_unsorted_three(lst1, lst2, size);
	    return ;
	}
	if (size == 4)
	{
		a_four(lst1, lst2);
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