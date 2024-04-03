/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidformat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:53:57 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 13:58:46 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

int	ft_isvalidformat(const char **format, va_list ap)
{
	int		bytes;
	int		idx;

	idx = 1;
	bytes = ft_checkformat(ap,*format, &idx);
	(*format) += idx;
	return (bytes);
}
