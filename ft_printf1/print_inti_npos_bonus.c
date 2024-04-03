/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inti_npos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:07:15 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/14 19:50:48 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	print_inti_npos(t_print *print, char *s, int size)
{
	if (print->flag[0])
	{
		if (print->flag[2])
			write(1, "+", 1);
		else if (print->flag[3])
			write(1, " ", 1);
		while (print->width-- > ft_max(print->flag[2], print->flag[3]))
			write(1, "0", 1);
	}
	else
	{
		while (print->width-- > ft_max(print->flag[2], print->flag[3]))
			write(1, " ", 1);
		if (print->flag[2])
			write(1, "+", 1);
		else if (print->flag[3])
			write(1, " ", 1);
	}
	while (print->length > size)
	{
		write(1, "0", 1);
		print->length--;
	}
	ft_putstr(s, print->length);
}
