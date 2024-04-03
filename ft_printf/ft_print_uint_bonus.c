/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:43:25 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:43:28 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_print_uint(va_list ap, t_print *print, int *len)
{
	char			*s;
	unsigned int	n;
	int				size;

	ft_setstate(ap, print);
	n = (unsigned int) va_arg(ap, int);
	s = ft_itoa_uint(n);
	if (!s)
	{
		(*len) = -1;
		return ;
	}
	size = ft_strlen(s);
	setuint(print, n, size, len);
	ft_printu(print, s, size);
	free(s);
}
