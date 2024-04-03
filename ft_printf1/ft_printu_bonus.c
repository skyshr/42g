/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:06:39 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:06:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_printu(t_print *print, char *s, int size)
{
	if (print->flag[1])
	{
		while (print->length > size)
		{
			write(1, "0", 1);
			print->length--;
		}
		ft_putstr(s, print->length);
	}
	while (print->width--)
	{
		if (print->flag[0] && !print->flag[1] && !print->precision)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	if (!print->flag[1])
	{
		while (print->length > size)
		{
			write(1, "0", 1);
			print->length--;
		}
		ft_putstr(s, print->length);
	}
}
