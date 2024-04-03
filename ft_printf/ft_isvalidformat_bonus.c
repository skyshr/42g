/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidformat_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:41:41 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:41:47 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

int	ft_isvalidformat(const char **format, va_list ap)
{
	t_print	*printinfo;
	int		bytes;
	int		idx;

	printinfo = (t_print *)malloc(sizeof(t_print));
	if (!printinfo)
		return (-1);
	if (!ft_setprint(printinfo))
		return (-1);
	idx = 1;
	ft_checkflag(printinfo, *format, &idx);
	ft_checkwidth(printinfo, *format, &idx);
	ft_checkprecision(printinfo, *format, &idx);
	ft_checklength(printinfo, *format, &idx);
	bytes = ft_checkformat(ap, printinfo, *format, &idx);
	(*format) += idx;
	free(printinfo->flag);
	free(printinfo);
	return (bytes);
}
