/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkprecision_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:04:43 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:04:46 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_checkprecision(t_print *print, char const *format, int *idx)
{
	if (format[*idx] == '.')
	{
		print->precision = 1;
		(*idx)++;
	}
}
