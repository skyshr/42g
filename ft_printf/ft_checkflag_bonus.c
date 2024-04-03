/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:04:17 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:04:21 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_checkflag(t_print *print, char const *format, int *idx)
{
	int	cur;

	cur = *idx;
	while (format[cur])
	{
		if (format[cur] == '0')
			print->flag[0] = 1;
		else if (format[cur] == '-')
			print->flag[1] = 1;
		else if (format[cur] == '+')
			print->flag[2] = 1;
		else if (format[cur] == ' ')
			print->flag[3] = 1;
		else if (format[cur] == '#')
			print->flag[4] = 1;
		else
			break ;
		cur++;
	}
	*idx = cur;
}
