/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printh_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:05:53 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:05:56 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_printh(t_print *print, char *s, int size, char *sign)
{
	if (print->precision || (*s == '0' && !print->width))
		print->flag[0] = 0;
	if (*s == '0')
		print->flag[4] = 0;
	if (print->flag[1])
		print_yhex(print, s, size, sign);
	else
		print_nhex(print, s, size, sign);
}
