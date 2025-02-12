/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:32:44 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/26 21:42:02 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_quotes_env(t_env *env, char **s);

void	copy_delimiter(char **read, char **str)
{
	if (**read != *(*read + 1))
	{
		*(*str)++ = *(*read)++;
		*(*str)++ = '\0';
	}
	else
	{
		*(*str)++ = *(*read)++;
		*(*str)++ = *(*read)++;
		*(*str)++ = '\0';
	}
}

void	handle_token(t_minishell *ms, char **read, char **str)
{
	char	*ptr;

	ptr = *str;
	if (ft_isparenthesis(**read))
	{
		while (ft_isparenthesis(**read))
			*(*str)++ = *(*read)++;
	}
	else if (!ft_isredirection(**read))
		copy_cmd_token(ms, read, str);
	else
		copy_rdt_token(ms, read, str);
	if (**read == '\0')
		return ;
	if (ptr != *str)
		*(*str)++ = '\0';
}

char	*translate(t_minishell *ms, char **str, int sign)
{
	(*str)++;
	if (**str == '$')
	{
		(*str)++;
		return (ft_itoa(getpid()));
	}
	else if (**str == '?')
	{
		(*str)++;
		return (ft_strdup(ms->exit_str));
	}
	else if (ft_isdigit(**str))
	{
		(*str)++;
		return (ft_strdup(""));
	}
	else if (ft_isquote(**str) && !sign)
		return (ft_strdup(""));
	else if (**str != '_' && !ft_isalpha(**str))
		return (ft_strdup("$"));
	else
		return (find_quotes_env(ms->head, str));
}

char	*find_quotes_env(t_env *env, char **str)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while ((*str)[i] && ((*str)[i] == '_' || ft_isalnum((*str)[i])))
		i++;
	key = ft_substr(*str, 0, i);
	if (key == NULL)
		error(4);
	value = env_get_value(key, env);
	free(key);
	*str += i;
	if (value == NULL)
		return (ft_strdup(""));
	return (ft_strdup(value));
}
