/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:25:12 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 14:29:03 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

void	ft_print_str(va_list ap, int *len)
{
	char	*s;
	void	*p;
	size_t	slen;

	p = va_arg(ap, char *);
	if (!p)
		s = "(null)";
	else
		s = (char *)p;
	slen = ft_strlen(s);
	(*len) += slen;
	ft_putstr(s, slen);
}
