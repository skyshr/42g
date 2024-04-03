/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printi_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:06:03 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:06:05 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_printi(t_print *print, char *s, int n, int size)
{
	if (print->precision || (!n && !print->width))
		print->flag[0] = 0;
	if (print->flag[1])
	{
		if (n >= 0)
			print_inti_ypos(print, s, size);
		else
			print_inti_yneg(print, s, size);
	}
	else
	{
		if (n >= 0)
			print_inti_npos(print, s, size);
		else
			print_inti_nneg(print, s, size);
	}
}
