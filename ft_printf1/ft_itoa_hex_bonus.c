/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:42:01 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:42:05 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

static size_t	ft_itoa_hexlen(int n);

char	*ft_itoa_hex(int n, char *base)
{
	char	*dest;
	size_t	totlen;
	size_t	destidx;

	if (n == 0)
		return (ft_strdup("0"));
	if (n > 0)
		totlen = ft_itoa_hexlen(n);
	else
	{
		n = n * -1 - 1;
		totlen = 8;
	}
	dest = (char *)malloc((totlen + 1) * sizeof(char));
	if (!dest)
		return (0);
	ft_memset(dest, base[0], sizeof(char) * totlen);
	destidx = totlen;
	dest[destidx--] = '\0';
	while (n > 0)
	{
		dest[destidx--] = base[n % 16];
		n /= 16;
	}
	return (dest);
}

size_t	ft_itoa_hexlen(int n)
{
	size_t	m;

	if (n == 0)
		return (1);
	m = 0;
	while (n > 0)
	{
		m++;
		n /= 16;
	}
	return (m);
}
