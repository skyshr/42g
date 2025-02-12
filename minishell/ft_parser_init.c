/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:47:13 by jajo              #+#    #+#             */
/*   Updated: 2024/06/26 20:47:32 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	create_parser(char *text)
{
	t_parser	parser;

	parser.lexer = create_lexer(text);
	return (parser);
}

t_lexer	create_lexer(char *text)
{
	t_lexer	lexer;

	lexer.text = text;
	lexer.position = 0;
	lexer.bracket_num = 0;
	lexer.is_bracket_closed = 0;
	lexer.token = get_next_token(&lexer);
	return (lexer);
}
