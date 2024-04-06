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
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

// typedef struct s_list
// {
// 	struct s_list	*prev;
// 	struct s_list	*next;
// 	int				n;
// }	t_list;

void	print_operations();
int		is_ordered(t_list *lst,	int	flag, size_t size);
int		get_num(char **argv, int *num);
int		isduplicate(int n, int m);
void	print_list(t_list *lst);
int		parse_single_arg(t_list **lst, char *argv);
void	parse_data(t_list **lst, int argc, char **argv);
void	push(t_list **lst1, t_list **lst2);
void	swap(t_list **lst);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
void	swap_both(t_list **lst1, t_list **lst2);
void	rotate_both(t_list **lst1, t_list **lst2);
void	reverse_rotate_both(t_list **lst1, t_list **lst2);
void	push_rotate(t_list **lst1, t_list **lst2);
void    a_four(t_list **lst1, t_list **lst2);
void	a_four_1243(t_list **lst1, t_list **lst2);
void	a_four_1324(t_list **lst1, t_list **lst2);
void	a_four_1342(t_list **lst1, t_list **lst2);
void	a_four_1423(t_list **lst1, t_list **lst2);
void	a_four_1432(t_list **lst1, t_list **lst2);
void	a_four_2134(t_list **lst1, t_list **lst2);
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
void    b_four(t_list **lst1, t_list **lst2);
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
void	b_handle_unsorted_three(t_list **lst1, t_list **lst2, int size);
void	b_divide_top_mid_bot(t_list **lst1, t_list **lst2, int left, int right);
void    b_to_a(t_list **lst1, t_list **lst2, int left, int right);
void	a_handle_unsorted_three(t_list **lst1, t_list **lst2, int size);
void	a_divide_top_mid_bot(t_list **lst1, t_list **lst2, int left, int right);
void    a_to_b(t_list **lst1, t_list **lst2, int left, int right);
void    handle_three(t_list **lst);
void	push_swap(t_list **lst1);
int		is_high(int m, int n);
void	order_data(t_list **lst);


#endif
