/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inti_yneg_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:07:20 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:07:22 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	print_inti_yneg(t_print *print, char *s, int size)
{
	write(1, "-", 1);
	print->length--;
	size--;
	while (print->length > size)
	{
		write(1, "0", 1);
		print->length--;
	}
	ft_putstr(s + 1, print->length);
	while (print->width--)
		write(1, " ", 1);
}
