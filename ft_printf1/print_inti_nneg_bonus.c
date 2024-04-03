/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inti_nneg_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:07:09 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:07:11 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	print_inti_nneg(t_print *print, char *s, int size)
{
	if (print->flag[0])
	{
		handle_length(print, &size);
		while (print->width--)
			write(1, "0", 1);
	}
	else
	{
		while (print->width--)
			write(1, " ", 1);
		handle_length(print, &size);
	}
	while (print->length > size)
	{
		write(1, "0", 1);
		print->length--;
	}
	ft_putstr(s + 1, print->length);
}
