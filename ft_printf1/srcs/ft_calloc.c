/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:09:52 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 15:10:05 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void		*dest;
	long long	i;
	long long	j;

	i = (long long)n;
	j = (long long)size;
	if (i * j > 2147483647)
		return (0);
	dest = malloc(n * size);
	if (!dest)
		return (0);
	ft_bzero(dest, n * size);
	return (dest);
}
