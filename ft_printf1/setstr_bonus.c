/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setstr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:08:05 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:08:06 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	setstr(t_print *print, char *s, int *len)
{
	if (!print->precision || print->length < 0)
		print->length = ft_strlen(s);
	print->length = ft_min(ft_strlen(s), print->length);
	if (print->width <= print->length)
		print->width = 0;
	else
		print->width -= print->length;
	(*len) += print->width + print->length;
}
