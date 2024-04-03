/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setuint_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:08:12 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:08:15 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	setuint(t_print *print, int n, int size, int *len)
{
	if (!print->precision || (print->length < size && n) || print->length < 0)
		print->length = size;
	if (print->width <= print->length)
		print->width = 0;
	else
		print->width -= print->length;
	(*len) += print->width + print->length;
}
