/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:32:18 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/03 07:15:16 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	itoa_len(unsigned int n);
static int	get_env_translate(t_env *env, char **s);

void	split_pipe_move_to_next_token(t_minishell *ms, char **str, int *len)
{
	int	tmp;

	tmp = **str;
	(*str)++;
	while (**str && **str != tmp)
	{
		if (tmp == 34 && **str == '$')
			(*len) += get_translate_len(ms, str, 1);
		else
		{
			(*len)++;
			(*str)++;
		}
	}
	(*str)++;
}

int	get_translate_len(t_minishell *ms, char **str, int sign)
{
	(*str)++;
	if (**str == '$')
	{
		(*str)++;
		return (itoa_len(getpid()));
	}
	else if ((**str) == '?')
		return (ft_strlen(ms->exit_str));
	else if (ft_isdigit(**str))
	{
		(*str)++;
		return (0);
	}
	else if (ft_isquote(**str))
		return (sign);
	else if (**str != '_' && !ft_isalpha(**str))
		return (1);
	else
		return (get_env_translate(ms->head, str));
}

int	itoa_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	get_env_translate(t_env *env, char **s)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while ((*s)[i] && ((*s)[i] == '_' || ft_isalnum((*s)[i])))
		i++;
	key = ft_substr(*s, 0, i);
	if (key == NULL)
		error(4);
	value = env_get_value(key, env);
	free(key);
	*s += i;
	return (ft_strlen(value));
}

int	handle_quotes(char *str)
{
	int	i;

	if (!ft_isquote(*str))
		return (0);
	i = 0;
	if (str[i] == 34)
	{
		i++;
		while (str[i] && str[i] != 34)
			i++;
	}
	else if (str[i] == 39)
	{
		i++;
		while (str[i] && str[i] != 39)
			i++;
	}
	i++;
	return (i);
}
