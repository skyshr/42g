/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:11:23 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/27 14:26:09 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_quotes_pair(char **str);

int	is_valid_quotes(char *str)
{
	int	res;

	res = 1;
	while (*str)
	{
		if (ft_isquote(*str))
			res = find_quotes_pair(&str);
		if (res == 0 || (*str) == '\0')
			break ;
		str++;
	}
	if (!res)
		ft_putendl_fd("bash: syntax error: unclosed quotes", STDERR_FILENO);
	return (res);
}

int	find_quotes_pair(char **str)
{
	int	start;

	start = **str;
	(*str)++;
	while (**str && **str != start)
		(*str)++;
	return ((**str) == start);
}
