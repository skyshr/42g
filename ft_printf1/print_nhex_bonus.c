/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nhex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:07:29 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:07:30 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	print_nhex(t_print *print, char *s, int size, char *sign)
{
	if (print->flag[4] && print->flag[0])
	{
		ft_putstr(sign, 2);
		print->length -= 2;
	}
	while (print->width--)
	{
		if (print->flag[0])
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	if (print->flag[4] && !print->flag[0])
	{
		ft_putstr(sign, 2);
		print->length -= 2;
	}
	while (print->length > size)
	{
		write(1, "0", 1);
		print->length--;
	}
	ft_putstr(s, print->length);
}
