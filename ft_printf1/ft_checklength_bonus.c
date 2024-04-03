/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checklength_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:04:34 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/14 19:40:18 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_checklength(t_print *print, char const *format, int *idx)
{
	int	length;
	int	cur;

	length = 0;
	cur = *idx;
	if (format[cur] == '*')
	{
		print->length = -1;
		(*idx)++;
		return ;
	}
	while (format[cur] >= '0' && format[cur] <= '9')
	{
		length = 10 * length + format[cur] - '0';
		cur++;
	}
	print->length = length;
	(*idx) = cur;
}
