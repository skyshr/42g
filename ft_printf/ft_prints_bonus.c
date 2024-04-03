/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:06:26 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:06:29 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	ft_prints(t_print *print, char *s)
{
	if (print->flag[1])
		ft_putstr(s, print->length);
	while (print->width--)
		write(1, " ", 1);
	if (!print->flag[1])
		ft_putstr(s, print->length);
}
