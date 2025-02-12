/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:07:23 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/27 13:01:37 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_token_len(t_minishell *ms, char **rdts);
static int	get_cmd_token_len(t_minishell *ms, char **str);
static int	get_rdt_token_len(t_minishell *ms, char **str);
static void	copy_string(char *str, char *read, t_minishell *ms);

char	*init_cmds_rdts(char *str, t_minishell *ms)
{
	char	*_str;
	char	*_result;
	char	*result;
	int		len;

	if (!is_valid_quotes(str))
		return (NULL);
	_str = str;
	len = 0;
	while (*str)
	{
		if (*str == '|' || *str == '&')
			len += get_limiter_len(&str);
		else
			len += get_token_len(ms, &str);
	}
	result = (char *)malloc((len + 2) * sizeof(char));
	ft_memset(result, 0, len + 2);
	if (!result)
		error(1);
	_result = result;
	copy_string(_result, _str, ms);
	return (result);
}

int	get_token_len(t_minishell *ms, char **s)
{
	int	l1;
	int	l2;

	l1 = 0;
	l2 = 0;
	while (ft_isspace(**s))
		(*s)++;
	if (ft_isparenthesis(**s))
	{
		while (ft_isparenthesis(**s))
		{
			(*s)++;
			l1++;
		}
		return (l1 + 1);
	}
	if (**s == '&' || **s == '|' || **s == '\0')
		return (0);
	if (!ft_isredirection(**s))
		return (get_cmd_token_len(ms, s));
	else
		return (get_rdt_token_len(ms, s));
}

int	get_cmd_token_len(t_minishell *ms, char **s)
{
	int	len;

	len = 2 + 2 * ft_isquote(**s);
	while (**s && **s != '>' && **s != '<' && !ft_isspace(**s) \
			&& **s != '|' && **s != '&' && !ft_isparenthesis(**s))
	{
		if (ft_isquote(**s))
			split_pipe_move_to_next_token(ms, s, &len);
		else if (**s == '$')
			len += get_translate_len(ms, s, 0);
		else
		{
			len++;
			(*s)++;
		}
	}
	return (len + 1);
}

int	get_rdt_token_len(t_minishell *ms, char **str)
{
	int	len;

	len = 0;
	if (**str == *(*str + 1))
	{
		len = 2;
		(*str) += 2;
	}
	else
	{
		len = 1;
		(*str)++;
	}
	while (ft_isspace(**str))
		(*str)++;
	return (len + get_cmd_token_len(ms, str) + 1);
}

void	copy_string(char *str, char *read, t_minishell *ms)
{
	while (*read)
	{
		if (*read == '|' || *read == '&')
			copy_delimiter(&read, &str);
		else
		{
			while (ft_isspace(*read))
				read++;
			handle_token(ms, &read, &str);
			while (ft_isspace(*read))
				read++;
		}
	}
	*str++ = '\0';
	*str++ = '\0';
}
