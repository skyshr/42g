/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setint_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:08:01 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:08:02 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	setint(t_print *print, int n, int size, int *len)
{
	if (print->length >= size && n < 0)
		print->length++;
	if (!print->precision || (print->length < size && n) || print->length < 0)
		print->length = size;
	if (print->width <= print->length)
	{
		if (n >= 0 && (print->flag[2] || print->flag[3]))
			print->width = 1;
		else
			print->width = 0;
	}
	else
		print->width -= print->length;
	(*len) += print->width + print->length;
}
