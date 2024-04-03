/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:22:59 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 20:30:15 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

void	ft_print_address(va_list ap, int *len)
{
	char	*s;
	size_t	slen;

	s = ft_itoa_address(va_arg(ap, void *), "0123456789abcdef");
	if (!s)
	{
		(*len) = -1;
		return ;
	}
	slen = ft_strlen(s);
	(*len) += slen;
	ft_putstr(s, slen);
	free(s);
}
