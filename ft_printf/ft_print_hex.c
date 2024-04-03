/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:43:19 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 14:47:14 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

void	ft_print_hex(va_list ap, int *len, int islower)
{
	char	*s;
	int		n;
	int		size;

	n = va_arg(ap, int);
	s = ft_itoa_hex(n, setbase(n, islower));
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
