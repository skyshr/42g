/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:42:36 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:42:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_print_char(va_list ap, t_print *print, int *len)
{
	char	c;

	ft_setstate(ap, print);
	c = va_arg(ap, int);
	if (!c)
		c = '\0';
	setchar(print, len);
	ft_printc(print, c);
}
