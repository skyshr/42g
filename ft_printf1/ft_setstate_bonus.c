/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setstate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:06:57 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:06:58 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_setstate(va_list ap, t_print *print)
{
	if (print->width == -1)
	{
		print->width = va_arg(ap, int);
		if (print->width < 0)
		{
			print->flag[1] = 1;
			print->width *= -1;
		}
	}
	if (print->length == -1)
		print->length = va_arg(ap, int);
}
