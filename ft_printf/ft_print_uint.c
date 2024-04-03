/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:32:42 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 14:37:11 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

void	ft_print_uint(va_list ap, int *len)
{
	char			*s;
	unsigned int	n;
	int				size;

	n = (unsigned int) va_arg(ap, int);
	s = ft_itoa_uint(n);
	if (!s)
	{
		(*len) = -1;
		return ;
	}
	size = ft_strlen(s);
	(*len) += size;
	ft_putstr(s, size);
	free(s);
}
