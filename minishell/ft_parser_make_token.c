/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_make_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:40:17 by jajo              #+#    #+#             */
/*   Updated: 2024/06/28 18:29:52 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	make_token_pipe_or(t_lexer *lexer)
{
	char	*text;

	text = lexer->text;
	lexer->position++;
	if (text[lexer->position] == '|')
	{
		lexer->position++;
		return ((t_token){TOKEN_OR, ft_par_strdup("||")});
	}
	return ((t_token){TOKEN_PIPE, ft_par_strdup("|")});
}

t_token	make_token_redirection_in(t_lexer *lexer)
{
	char	*text;

	text = lexer->text;
	lexer->position++;
	if (text[lexer->position] == '<')
	{
		lexer->position++;
		return ((t_token){TOKEN_REDIR_DOUBLE_IN, ft_par_strdup("<<")});
	}
	return ((t_token){TOKEN_REDIR_IN, ft_par_strdup("<")});
}

t_token	make_token_redirection_out(t_lexer *lexer)
{
	char	*text;

	text = lexer->text;
	lexer->position++;
	if (text[lexer->position] == '>')
	{
		lexer->position++;
		return ((t_token){TOKEN_REDIR_DOUBLE_OUT, ft_par_strdup(">>")});
	}
	return ((t_token){TOKEN_REDIR_OUT, ft_par_strdup(">")});
}

t_token	make_token_and(t_lexer *lexer)
{
	char	*text;

	text = lexer->text;
	lexer->position++;
	if (text[lexer->position] == '&')
	{
		lexer->position++;
		return ((t_token){TOKEN_AND, ft_par_strdup("&&")});
	}
	return ((t_token){TOKEN_ERROR, ft_par_strdup("&")});
}

t_token	make_token_string(t_lexer *lexer)
{
	char	*text;
	int		start;
	int		len;
	char	*value;

	text = lexer->text;
	start = lexer->position;
	make_token_string_utils(lexer);
	len = lexer->position - start - 2;
	if (len == 0)
		return ((t_token){TOKEN_STRING, NULL});
	if (len >= 2 && text[start + 1] == 34 && text[lexer->position - 2] == 34)
	{
		len -= 2;
		start++;
	}
	start++;
	value = (char *)malloc(len + 1);
	if (!value)
		error(4);
	ft_strncpy(value, text + start, len);
	value[len] = '\0';
	return ((t_token){TOKEN_STRING, value});
}
