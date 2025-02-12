/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:05:04 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 18:20:15 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	handle_multi_cmd1(t_treenode *root, t_minishell *ms)
{
	int	status;

	if (g_exit_status)
		return (g_exit_status);
	if (root->type != NODE_PIPE && !is_nodetype_and_or(root->type))
		return (handle_multi_cmd(ms, -1));
	status = 0;
	ms->root = root;
	if (root->left)
	{
		if (root->left->type == NODE_PIPE || \
			is_nodetype_and_or(root->left->type))
		{
			status = handle_multi_cmd1(root->left, ms);
			if (root->right)
			{
				ms->root = root;
				ms->node_type = root->type;
				return (handle_multi_cmd(ms, status));
			}
		}
		else
			status = handle_multi_cmd(ms, -1);
	}
	return (status);
}
