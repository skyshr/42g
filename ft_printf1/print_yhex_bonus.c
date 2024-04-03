/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_yhex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:07:33 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:07:34 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	print_yhex(t_print *print, char *s, int size, char *sign)
{
	if (print->flag[4])
	{
		if (*s != '0')
		{
			ft_putstr(sign, 2);
			print->length -= 2;
		}
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
