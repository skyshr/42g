/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_lexer_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:32:56 by jajo              #+#    #+#             */
/*   Updated: 2024/06/26 19:30:45 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	advance(t_lexer *lexer)
{
	if (lexer->token.type != TOKEN_EOF)
	{
		if (lexer->token.value)
			free(lexer->token.value);
		lexer->token = get_next_token(lexer);
		while (lexer->token.type == TOKEN_STRING && lexer->token.value == NULL)
			lexer->token = get_next_token(lexer);
	}
}

void	skip_white_space(t_lexer *lexer)
{
	char	*text;

	text = lexer->text;
	while (text[lexer->position] != '\0' || text[lexer->position + 1] != '\0')
	{
		if (ft_isspace(text[lexer->position]) || text[lexer->position] == '\0')
			lexer->position++;
		else
			return ;
	}
}

int	skip_bracket(t_lexer *lexer)
{
	char	*text;
	int		num;

	num = 0;
	text = lexer->text;
	while (text[lexer->position] != '\0' || text[lexer->position + 1] != '\0')
	{
		if (text[lexer->position] != '(' && text[lexer->position] != ')')
			break ;
		if (text[lexer->position] == '(')
		{
			lexer->is_bracket_closed = 0;
			lexer->position++;
			num++;
		}
		else if (text[lexer->position] == ')')
		{
			lexer->is_bracket_closed = 1;
			lexer->position++;
			num--;
		}
		if (text[lexer->position] == '\0')
			skip_white_space(lexer);
	}
	return (num);
}

int	is_special_command(t_parser *parser)
{
	return (parser->lexer.token.type != TOKEN_STRING
		&& parser->lexer.token.type != TOKEN_EOF);
}
