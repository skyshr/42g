/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:41:14 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:41:35 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

int	ft_checkformat(va_list ap, t_print *print, char const *format, int *idx)
{
	int	cur;
	int	len;

	cur = *idx;
	len = 0;
	if (format[cur] == 'c')
		ft_print_char(ap, print, &len);
	else if (format[cur] == 's')
		ft_print_str(ap, print, &len);
	else if (format[cur] == 'p')
		ft_print_address(ap, print, &len);
	else if (format[cur] == 'd' || format[cur] == 'i')
		ft_print_int(ap, print, &len);
	else if (format[cur] == 'u')
		ft_print_uint(ap, print, &len);
	else if (format[cur] == 'x' || format[cur] == 'X')
		ft_print_hex(ap, print, &len, (format[cur] == 'x'));
	else if (format[cur] == '%')
		ft_print_percent(&len);
	(*idx)++;
	return (len);
}
