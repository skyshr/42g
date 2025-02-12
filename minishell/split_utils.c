/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:10:41 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/26 09:36:41 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_limiter_len(char **str)
{
	if (**str != *(*str + 1))
	{
		(*str)++;
		return (2);
	}
	*str += 2;
	return (3);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	get_args_len(char **args)
{
	int	n;

	if (!args)
		return (0);
	n = 0;
	while (args[n])
		n++;
	return (n);
}

char	**free_split(char **split, size_t m)
{
	size_t	n;

	n = 0;
	while (n < m)
		free(split[n++]);
	free(split);
	return (NULL);
}
