/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uint_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:42:16 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:42:21 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

static size_t	ft_itoasize(unsigned int n);

char	*ft_itoa_uint(unsigned int n)
{
	char			*dest;
	size_t			destidx;
	size_t			len;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_itoasize(n);
	destidx = len;
	dest = (char *)malloc((destidx + 1) * sizeof(char));
	if (!dest)
		return (0);
	dest[destidx--] = '\0';
	while (n > 0)
	{
		dest[destidx--] = '0' + n % 10;
		n /= 10;
	}
	return (dest);
}

size_t	ft_itoasize(unsigned int n)
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
