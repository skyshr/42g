/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:42:44 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:42:48 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		totalbytes;
	int		addbytes;

	totalbytes = 0;
	va_start(ap, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			write(1, format++, 1);
			totalbytes++;
		}
		if (*format)
		{
			addbytes = ft_isvalidformat(&format, ap);
			if (addbytes < 0)
				return (-1);
			totalbytes += addbytes;
		}
	}
	va_end(ap);
	return (totalbytes);
}
