/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:50:09 by ksuh              #+#    #+#             */
/*   Updated: 2024/05/07 14:56:31 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*u1;
	const unsigned char	*u2;

	u1 = (const unsigned char *)s1;
	u2 = (const unsigned char *)s2;
	while (*u1 && *u1 == *u2)
	{
		u1++;
		u2++;
	}
	return (*u1 - *u2);
}
