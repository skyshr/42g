/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:31:13 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/14 19:43:02 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

void	ft_print_char(va_list ap, int *len)
{
	char	c;

	c = va_arg(ap, int);
	*len += 1;
	write(1, &c, 1);
}
