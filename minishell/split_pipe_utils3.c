/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:36:26 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/26 09:44:56 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	translate_token(t_minishell *ms, char **str, char *dest, int sign);
static int	translate_quoted_token(t_minishell *ms, char **str, char *dest);

void	copy_cmd_token(t_minishell *ms, char **str, char **cmds)
{
	int	i;
	int	tmp;

	*(*cmds)++ = 34;
	tmp = ft_isquote(**str);
	if (tmp)
		*(*cmds)++ = 34;
	while (**str && !ft_isredirection(**str) && !ft_isspace(**str) \
			&& !ft_isoperand(**str) && !ft_isparenthesis(**str))
	{
		if (**str == '$' || ft_isquote(**str))
		{
			if (**str == '$')
				i = translate_token(ms, str, *cmds, 0);
			else
				i = translate_quoted_token(ms, str, *cmds);
			(*cmds) += i;
		}
		else
			*(*cmds)++ = *(*str)++;
	}
	if (tmp)
		*(*cmds)++ = 34;
	*(*cmds)++ = 34;
}

void	copy_rdt_token(t_minishell *ms, char **str, char **rdts)
{
	if (**str == *(*str + 1))
	{
		*(*rdts)++ = *(*str)++;
		*(*rdts)++ = *(*str)++;
	}
	else
		*(*rdts)++ = *(*str)++;
	while (ft_isspace(**str))
		(*str)++;
	*(*rdts)++ = ' ';
	copy_cmd_token(ms, str, rdts);
}

int	translate_token(t_minishell *ms, char **str, char *dest, int sign)
{
	char	*token;
	int		len;

	token = translate(ms, str, sign);
	if (token == NULL)
		error(4);
	len = ft_strlen(token);
	ft_strlcpy(dest, token, len + 1);
	free(token);
	return (len);
}

int	translate_quoted_token(t_minishell *ms, char **str, char *dest)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = *(*str)++;
	while (**str && **str != tmp)
	{
		if (tmp == 34 && **str == '$')
		{
			j = translate_token(ms, str, &dest[i], 1);
			if (j == -1)
				return (-1);
			i += j;
		}
		else
		{
			dest[i++] = **str;
			(*str)++;
		}
	}
	(*str)++;
	return (i);
}
