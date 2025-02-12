/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_make_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:59:55 by jajo              #+#    #+#             */
/*   Updated: 2024/06/28 18:29:16 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_treenode	*make_new_node(t_parser *parser)
{
	t_treenode	*new_node;

	new_node = (t_treenode *)malloc(sizeof(t_treenode));
	if (!new_node)
		error(4);
	new_node->type = (t_nodetype)parser->lexer.token.type;
	new_node->command = ft_par_strdup(parser->lexer.token.value);
	new_node->start_bracket = parser->lexer.bracket_num;
	new_node->end_bracket = 0;
	new_node->arguments = NULL;
	new_node->arg_count = 0;
	if (new_node->type == NODE_PIPE)
		new_node->is_closed_prev = 0;
	else
		new_node->is_closed_prev = parser->lexer.is_bracket_closed;
	return (new_node);
}

t_treenode	*make_null_node(t_parser *parser)
{
	t_treenode	*node;

	node = (t_treenode *)malloc(sizeof(t_treenode));
	if (!node)
		error(4);
	node->type = NODE_COMMAND;
	node->command = NULL;
	node->arg_count = 1;
	node->start_bracket = parser->lexer.bracket_num;
	node->end_bracket = 0;
	node->arguments = malloc(sizeof(char *));
	if (!node->arguments)
		error(4);
	node->arguments[0] = NULL;
	node->is_closed_prev = parser->lexer.is_bracket_closed;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_treenode	*make_command_new_node(t_parser *parser)
{
	t_treenode	*node;

	node = (t_treenode *)malloc(sizeof(t_treenode));
	if (!node)
		error(4);
	node->type = NODE_COMMAND;
	node->command = ft_par_strdup(parser->lexer.token.value);
	node->arg_count = 0;
	node->start_bracket = parser->lexer.bracket_num;
	node->end_bracket = 0;
	node->arguments = malloc(sizeof(char *) * 2);
	if (!node->arguments)
		error(4);
	node->arguments[0] = ft_par_strdup(node->command);
	node->arguments[1] = NULL;
	node->is_closed_prev = parser->lexer.is_bracket_closed;
	if (node->command)
		node->arg_count++;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	make_token_string_utils(t_lexer *lexer)
{
	char	*text;

	text = lexer->text;
	while (text[lexer->position] != '\0')
		lexer->position++;
}
