/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:05:38 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:05:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_printc(t_print *print, char c)
{
	if (print->flag[1])
		write(1, &c, 1);
	while (print->width--)
		write(1, " ", 1);
	if (!print->flag[1])
		write(1, &c, 1);
}
