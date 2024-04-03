/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:15:58 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 15:32:58 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

int	ft_checkformat(va_list ap, char const *format, int *idx)
{
	int	cur;
	int	len;

	cur = *idx;
	len = 0;
	if (format[cur] == 'c')
		ft_print_char(ap, &len);
	else if (format[cur] == 's')
		ft_print_str(ap, &len);
	else if (format[cur] == 'p')
		ft_print_address(ap, &len);
	else if (format[cur] == 'd' || format[cur] == 'i')
		ft_print_int(ap, &len);
	else if (format[cur] == 'u')
		ft_print_uint(ap, &len);
	else if (format[cur] == 'x' || format[cur] == 'X')
		ft_print_hex(ap, &len, (format[cur] == 'x'));
	else if (format[cur] == '%')
		ft_print_percent(&len);
	(*idx)++;
	return (len);
}
