/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:42:51 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:42:55 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_print_hex(va_list ap, t_print *print, int *len, int islower)
{
	char	*s;
	char	*sign;
	int		n;
	int		size;

	ft_setstate(ap, print);
	n = va_arg(ap, int);
	s = ft_itoa_hex(n, setbase(n, islower));
	if (!s)
	{
		(*len) = -1;
		return ;
	}
	if (islower)
		sign = "0x";
	else
		sign = "0X";
	size = ft_strlen(s);
	sethex(print, n, size, len);
	ft_printh(print, s, size, sign);
	free(s);
}
