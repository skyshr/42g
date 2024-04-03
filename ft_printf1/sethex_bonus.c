/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sethex_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:07:57 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:07:58 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	sethex(t_print *print, int n, int size, int *len)
{
	if (!print->precision || (print->length < size && n) || print->length < 0)
		print->length = size;
	if (print->flag[4] && n != 0)
		print->length += 2;
	if (print->width <= print->length)
		print->width = 0;
	else
		print->width -= print->length;
	(*len) += print->width + print->length;
}
