/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:36:07 by jajo              #+#    #+#             */
/*   Updated: 2024/06/26 20:48:12 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_tree_utils(t_treenode *root, t_minishell *ms)
{
	return (((ms->root == root && root->right->is_closed_prev
				&& root->right->start_bracket != 0)
			|| (root->right->is_closed_prev
				&& root->right->start_bracket == 0)));
}

int	get_treenode_num(t_treenode *root)
{
	int	count;
	int	count_left;
	int	count_right;

	if (root->type == NODE_REDIR_DOUBLE_IN || \
		root->type == NODE_REDIR_DOUBLE_OUT || \
		root->type == NODE_REDIR_IN || \
		root->type == NODE_REDIR_OUT)
		return (get_treenode_num(root->left));
	if (root->type == NODE_COMMAND)
		return (1);
	count = 0;
	if (root != NULL)
	{
		count_left = get_treenode_num(root->left);
		count_right = get_treenode_num(root->right);
		count = count_left + count_right;
	}
	return (count);
}

int	check_tree_validation(t_treenode *root)
{
	int	tmp;

	if (!root)
		return (0);
	if (root->type == NODE_ERROR)
		return (3);
	if (root->type == NODE_PIPE || root->type == NODE_OR \
		|| root->type == NODE_AND)
	{
		if (root->left == NULL || root->right == NULL || \
		(root->left->type == NODE_COMMAND && root->left->command == NULL) || \
		(root->right->type == NODE_COMMAND && root->right->command == NULL))
			return (1);
	}
	if (root->type == NODE_REDIR_OUT || root->type == NODE_REDIR_IN || \
	root->type == NODE_REDIR_DOUBLE_IN || root->type == NODE_REDIR_DOUBLE_OUT)
	{
		if (root->right == NULL || root->right->command == NULL)
			return (2);
	}
	tmp = check_tree_validation(root->left);
	if (tmp)
		return (tmp);
	tmp = check_tree_validation(root->right);
	return (tmp);
}

void	free_tree(t_treenode *root)
{
	int	i;

	i = -1;
	if (!root)
		return ;
	while (++i < root->arg_count)
		free(root->arguments[i]);
	if (root->type == NODE_COMMAND && root->command != NULL)
		free(root->arguments[i]);
	if (root->command)
	{
		free(root->command);
		root->command = NULL;
	}
	free(root->arguments);
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}
