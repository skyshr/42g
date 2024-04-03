/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:07:03 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:07:05 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

void	handle_length(t_print *print, int *size)
{
	write(1, "-", 1);
	print->length--;
	(*size)--;
}
