/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setbase_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:43:33 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 21:43:38 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlibft_bonus.h"

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
