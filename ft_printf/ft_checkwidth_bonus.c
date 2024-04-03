/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwidth_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:04:49 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:04:51 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_checkwidth(t_print *print, char const *format, int *idx)
{
	int	width;
	int	cur;

	width = 0;
	cur = *idx;
	if (format[cur] == '*')
	{
		print->width = -1;
		(*idx)++;
		return ;
	}
	while (format[cur] >= '0' && format[cur] <= '9')
	{
		width = 10 * width + format[cur] - '0';
		cur++;
	}
	print->width = width;
	(*idx) = cur;
}
