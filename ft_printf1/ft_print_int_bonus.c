/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:42:59 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:43:04 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_print_int(va_list ap, t_print *print, int *len)
{
	char	*s;
	int		n;
	int		size;

	ft_setstate(ap, print);
	n = va_arg(ap, int);
	s = ft_itoa_int(n);
	if (!s)
	{
		(*len) = -1;
		return ;
	}
	size = ft_strlen(s);
	setint(print, n, size, len);
	ft_printi(print, s, n, size);
	free(s);
}
