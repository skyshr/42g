/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inti_ypos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:07:25 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:07:26 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	print_inti_ypos(t_print *print, char *s, int size)
{
	if (print->flag[2] || print->flag[3])
	{
		if (print->flag[2])
			write(1, "+", 1);
		else
			write(1, " ", 1);
		print->width--;
	}
	while (print->length > size)
	{
		write(1, "0", 1);
		print->length--;
	}
	ft_putstr(s, print->length);
	while (print->width--)
		write(1, " ", 1);
}
