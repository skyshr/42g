/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setbase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:02:44 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 21:05:20 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft.h"

char	*setbase(int n, int islower)
{
	char	*base;

	if (n < 0)
	{
		if (islower)
			base = "fedcba9876543210";
		else
			base = "FEDCBA9876543210";
	}
	else
	{
		if (islower)
			base = "0123456789abcdef";
		else
			base = "0123456789ABCDEF";
	}
	return (base);
}
