/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:36:16 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 20:36:19 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

static size_t	ft_itoa_addrlen(unsigned long long n);

char	*ft_itoa_address(void *p, char *base)
{
	unsigned long long	n;
	char				*dest;
	size_t				totlen;
	size_t				destidx;

	if (!p)
		return (ft_strdup("(nil)"));
	n = (unsigned long long)p;
	totlen = ft_itoa_addrlen(n) + 3;
	destidx = totlen - 1;
	dest = (char *)malloc(totlen * sizeof(char));
	if (!dest)
		return (0);
	ft_memset(dest, '0', totlen);
	dest[destidx--] = '\0';
	while (n > 0)
	{
		dest[destidx--] = base[n % 16];
		n /= 16;
	}
	dest[0] = '0';
	dest[1] = 'x';
	return (dest);
}

size_t	ft_itoa_addrlen(unsigned long long n)
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
