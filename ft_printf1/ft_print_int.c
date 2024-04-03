/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:10:07 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 14:14:57 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

void	ft_print_int(va_list ap, int *len)
{
	char	*s;
	int		n;
	int		size;

	n = va_arg(ap, int);
	s = ft_itoa_int(n);
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
