/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setprint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:06:49 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:06:50 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

int	ft_setprint(t_print *print)
{
	print->flag = (int *)calloc(5, sizeof(int));
	if (!print->flag)
		return (0);
	print->width = 0;
	print->precision = 0;
	print->length = 0;
	return (1);
}
