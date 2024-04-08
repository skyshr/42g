/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:19:12 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/03 11:19:15 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line_bonus.h"

typedef struct s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	int				n;
	int				order;
}	t_list;

int		ft_isalpha(int c);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_list	*ft_lstnew(int n);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstiter(t_list *lst, int n, int (*f)(int, int));
int		ft_isdigit(int c);
int		is_ordered(t_list *lst,	int	flag, size_t size);
int		get_num(char **argv, int *num);
int		is_duplicate(int n, int m);
void	print_list(t_list *lst);
void	parse_singlearg(t_list **lst, char *argv);
void	parse_multiarg(t_list **lst, int argc, char **argv);
void	parse_data(t_list **lst, int argc, char **argv);
void	push(t_list **lst1, t_list **lst2, int sign);
void	swap(t_list **lst, int sign);
void	rotate(t_list **lst, int sign);
void	reverse_rotate(t_list **lst, int sign);
void	swap_both(t_list **lst1, t_list **lst2, int sign);
void	rotate_both(t_list **lst1, t_list **lst2, int sign);
void	reverse_rotate_both(t_list **lst1, t_list **lst2, int sign);
void	push_rotate(t_list **lst1, t_list **lst2, int sign);
void    a_four(t_list **lst1, t_list **lst2);
void	a_four_first(t_list **lst1, t_list **lst2);
void	a_four_second(t_list **lst1, t_list **lst2);
void	a_four_third(t_list **lst1, t_list **lst2);
void	a_four_fourth(t_list **lst1, t_list **lst2);
void	a_four_fifth(t_list **lst1, t_list **lst2);
void	a_four_sixth(t_list **lst1, t_list **lst2);
void	a_four_1243(t_list **lst1, t_list **lst2);
void	a_four_1324(t_list **lst1, t_list **lst2);
void	a_four_1342(t_list **lst1, t_list **lst2);
void	a_four_1423(t_list **lst1, t_list **lst2);
void	a_four_1432(t_list **lst1, t_list **lst2);
void	a_four_2134(t_list **lst1);
void	a_four_2143(t_list **lst1, t_list **lst2);
void	a_four_2314(t_list **lst1, t_list **lst2);
void	a_four_2341(t_list **lst1, t_list **lst2);
void	a_four_2413(t_list **lst1, t_list **lst2);
void	a_four_2431(t_list **lst1, t_list **lst2);
void	a_four_3124(t_list **lst1, t_list **lst2);
void	a_four_3142(t_list **lst1, t_list **lst2);
void	a_four_3214(t_list **lst1, t_list **lst2);
void	a_four_3241(t_list **lst1, t_list **lst2);
void	a_four_3412(t_list **lst1, t_list **lst2);
void	a_four_3421(t_list **lst1, t_list **lst2);
void	a_four_4123(t_list **lst1, t_list **lst2);
void	a_four_4132(t_list **lst1, t_list **lst2);
void	a_four_4213(t_list **lst1, t_list **lst2);
void	a_four_4231(t_list **lst1, t_list **lst2);
void	a_four_4312(t_list **lst1, t_list **lst2);
void	a_four_4321(t_list **lst1, t_list **lst2);
void	b_three(t_list **lst1, t_list **lst2);
void    b_four(t_list **lst1, t_list **lst2);
void	b_four_first(t_list **lst1, t_list **lst2);
void	b_four_second(t_list **lst1, t_list **lst2);
void	b_four_third(t_list **lst1, t_list **lst2);
void	b_four_fourth(t_list **lst1, t_list **lst2);
void	b_four_fifth(t_list **lst1, t_list **lst2);
void	b_four_sixth(t_list **lst1, t_list **lst2);
void	b_four_1234(t_list **lst1, t_list **lst2);
void	b_four_1243(t_list **lst1, t_list **lst2);
void	b_four_1324(t_list **lst1, t_list **lst2);
void	b_four_1342(t_list **lst1, t_list **lst2);
void	b_four_1423(t_list **lst1, t_list **lst2);
void	b_four_1432(t_list **lst1, t_list **lst2);
void	b_four_2134(t_list **lst1, t_list **lst2);
void	b_four_2143(t_list **lst1, t_list **lst2);
void	b_four_2314(t_list **lst1, t_list **lst2);
void	b_four_2341(t_list **lst1, t_list **lst2);
void	b_four_2413(t_list **lst1, t_list **lst2);
void	b_four_2431(t_list **lst1, t_list **lst2);
void	b_four_3124(t_list **lst1, t_list **lst2);
void	b_four_3142(t_list **lst1, t_list **lst2);
void	b_four_3214(t_list **lst1, t_list **lst2);
void	b_four_3241(t_list **lst1, t_list **lst2);
void	b_four_3412(t_list **lst1, t_list **lst2);
void	b_four_3421(t_list **lst1, t_list **lst2);
void	b_four_4123(t_list **lst1, t_list **lst2);
void	b_four_4132(t_list **lst1, t_list **lst2);
void	b_four_4213(t_list **lst1, t_list **lst2);
void	b_four_4231(t_list **lst1, t_list **lst2);
void	b_four_4312(t_list **lst1, t_list **lst2);
void    a_three_132(t_list **lst1, t_list **lst2);
void    a_three_213(t_list **lst);
void    a_three_231(t_list **lst1, t_list **lst2);
void    a_three_312(t_list **lst1, t_list **lst2);
void    a_three_321(t_list **lst1, t_list **lst2);
void    b_two(t_list **lst1, t_list **lst2);
void    b_three_123(t_list **lst1, t_list **lst2);
void    b_three_132(t_list **lst1, t_list **lst2);
void    b_three_213(t_list **lst1, t_list **lst2);
void    b_three_231(t_list **lst1, t_list **lst2);
void    b_three_312(t_list **lst1, t_list **lst2);
void	b_handle_unsorted_four(t_list **lst1, t_list **lst2, int size);
void	b_divide_top_mid_bot(t_list **lst1, t_list **lst2, int left, int right);
void    b_to_a(t_list **lst1, t_list **lst2, int left, int right);
void	a_handle_unsorted_four(t_list **lst1, t_list **lst2, int size);
void	a_divide_top_mid_bot(t_list **lst1, t_list **lst2, int left, int right);
void    a_to_b(t_list **lst1, t_list **lst2, int left, int right);
void	a_three(t_list **lst1, t_list **lst2);
void	push_swap(t_list **lst1, int size);
int		is_high(int m, int n);
void	order_data(t_list **lst, int size);

#endif
