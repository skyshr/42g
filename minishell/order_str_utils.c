/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_str_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:05:11 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/26 09:48:33 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_str(char **str, char *dest, int *i)
{
	dest[(*i)++] = *(*str)++;
	if (**str == '\0' && *(*str + 1) == '\0')
		dest[(*i)++] = '\0';
}

void	copy_rdt(char **str, char *dest, int *i)
{
	while (**str)
		dest[(*i)++] = *(*str)++;
	if (*(*str + 1))
		dest[(*i)++] = *(*str)++;
	else
		dest[(*i)++] = **str;
}
