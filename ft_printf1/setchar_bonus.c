/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setchar_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:07:52 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:07:54 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	setchar(t_print *print, int *len)
{
	print->length = 1;
	if (print->width > 0)
		print->width -= 1;
	(*len) += print->width + print->length;
}
