/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:08:26 by jajo              #+#    #+#             */
/*   Updated: 2024/06/28 18:32:34 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_tree(t_treenode *root, t_minishell *ms)
{
	t_treenode	*node_tmp;
	t_treenode	*tmp;

	if (!root->right || root->right->type == NODE_COMMAND)
		return ;
	node_tmp = root->right;
	tmp = root->right->left;
	if (ms->root != root && root->right->is_closed_prev
		&& root->right->start_bracket != 0)
	{
		root->right = tmp;
		node_tmp -> left = root;
		ms->tmp_root->right = node_tmp;
		change_tree(ms->tmp_root->right, ms);
	}
	else if (change_tree_utils(root, ms))
	{
		root->right = tmp;
		node_tmp ->left = ms->root;
		ms -> root = node_tmp;
		ms -> tmp_root = node_tmp;
		change_tree(ms->root, ms);
	}
	change_tree(root->right, ms);
}

t_treenode	*do_parse_input(t_minishell *ms, char *input)
{
	int			errnum;
	t_parser	parser;
	t_treenode	*root;

	parser = create_parser(input);
	root = parse_command(&parser);
	ms->root = root;
	ms->tmp_root = root;
	if (!root)
		return (NULL);
	errnum = check_tree_validation(root);
	if (errnum)
	{
		ms->exit = 2;
		ft_putendl_fd("bash: syntax error", STDERR_FILENO);
		return (free_tree(ms->root), NULL);
	}
	ms->treenode_num = get_treenode_num(root);
	change_tree(root, ms);
	ms->root = ms->tmp_root;
	return (ms->root);
}

t_token	get_next_token(t_lexer *lexer)
{
	char	*text;

	text = lexer->text;
	while (text[lexer->position] != '\0' || text[lexer->position + 1] != '\0')
	{
		skip_white_space(lexer);
		lexer->bracket_num += skip_bracket(lexer);
		if (text[lexer->position] == '\0' && text[lexer->position + 1] == '\0')
			break ;
		if (text[lexer->position] == '|')
			return (make_token_pipe_or(lexer));
		if (text[lexer->position] == '<')
			return (make_token_redirection_in(lexer));
		if (text[lexer->position] == '>')
			return (make_token_redirection_out(lexer));
		if (text[lexer->position] == '&')
			return (make_token_and(lexer));
		return (make_token_string(lexer));
	}
	return ((t_token){TOKEN_EOF, NULL});
}

t_treenode	*parse_command(t_parser *parser)
{
	t_treenode	*node;
	t_treenode	*new_node;

	node = parse_simple_command(parser);
	while (is_special_command(parser))
	{
		new_node = make_new_node(parser);
		new_node->left = node;
		advance(&parser->lexer);
		parser->lexer.bracket_num += skip_bracket(&parser->lexer);
		new_node->end_bracket = parser->lexer.bracket_num;
		if (new_node->start_bracket > new_node->end_bracket)
			parser->lexer.is_bracket_closed = 1;
		else
			parser->lexer.is_bracket_closed = 0;
		if (new_node->type == TOKEN_PIPE || new_node->type == TOKEN_AND
			|| new_node->type == TOKEN_OR)
			new_node->right = parse_command(parser);
		else
			new_node->right = parse_simple_command(parser);
		node = new_node;
	}
	return (node);
}

t_treenode	*parse_simple_command(t_parser *parser)
{
	t_treenode	*node;
	int			count;

	if (parser->lexer.token.type != TOKEN_STRING)
		return (make_null_node(parser));
	node = make_command_new_node(parser);
	advance(&parser->lexer);
	parser->lexer.bracket_num += skip_bracket(&parser->lexer);
	node->end_bracket = parser->lexer.bracket_num;
	while (parser->lexer.token.type == TOKEN_STRING)
	{
		if (parser->lexer.token.value != NULL)
		{
			if (node->command == NULL)
				node->command = ft_par_strdup(parser->lexer.token.value);
			count = node->arg_count;
			node->arguments = ft_realloc(node->arguments, (count + 1));
			node->arguments[count] = ft_par_strdup(parser->lexer.token.value);
			node->arg_count++;
		}
		advance(&parser->lexer);
	}
	return (node);
}
