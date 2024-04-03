/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setaddr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:07:37 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:07:39 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	setaddr(t_print *print, char *s, int *len)
{
	print->length = ft_strlen(s);
	if (print->width >= print->length)
		print->width -= print->length;
	else
		print->width = 0;
	(*len) += print->width + print->length;
}
