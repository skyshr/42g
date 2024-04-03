/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:42:26 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:42:30 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_print_address(va_list ap, t_print *print, int *len)
{
	char	*s;

	ft_setstate(ap, print);
	s = ft_itoa_address(va_arg(ap, void *), "0123456789abcdef");
	if (!s)
	{
		(*len) = -1;
		return ;
	}
	setaddr(print, s, len);
	ft_printp(print, s);
	free(s);
}
