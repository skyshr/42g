/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:43:18 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:43:22 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_print_str(va_list ap, t_print *print, int *len)
{
	char	*s;
	void	*p;

	ft_setstate(ap, print);
	p = va_arg(ap, char *);
	if (!p)
	{
		s = "(null)";
		if (print->length < 6 && print->length >= 0)
			print->length = 0;
		else
			print->length = 6;
	}
	else
		s = (char *)p;
	setstr(print, s, len);
	ft_prints(print, s);
}
