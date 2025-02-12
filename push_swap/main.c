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

int	main(int argc, char **argv)
{
	t_list	*lst;
	int		size;

	lst = NULL;
	parse_data(&lst, argc, argv);
	size = ft_lstsize(lst);
	order_data(&lst, size);
	push_swap(&lst, size);
	ft_lstclear(&lst);
	return (0);
}
