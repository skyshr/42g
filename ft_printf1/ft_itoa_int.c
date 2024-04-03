/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:30:48 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 14:30:59 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

static size_t	ft_itoa_intlen(unsigned int n);

char	*ft_itoa_int(int n)
{
	unsigned int	i;
	char			*dest;
	size_t			totlen;
	size_t			destidx;

	if (n == 0)
		return (ft_strdup("0"));
	i = n;
	if (n < 0)
		i = (unsigned int)-n;
	totlen = ft_itoa_intlen(i) + (n < 0) + 1;
	destidx = totlen - 1;
	dest = (char *)calloc(totlen, sizeof(char));
	if (!dest)
		return (0);
	if (n < 0)
		dest[0] = '-';
	while (i > 0)
	{
		dest[--destidx] = '0' + i % 10;
		i /= 10;
	}
	return (dest);
}

size_t	ft_itoa_intlen(unsigned int n)
{
	size_t	m;

	m = 0;
	while (n > 0)
	{
		m++;
		n /= 10;
	}
	return (m);
}
