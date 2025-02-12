/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_interpret_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:55:28 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 20:52:50 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*dup_token(char **str)
{
	char	*res;
	int		i;

	i = 0;
	(*str)++;
	while ((*str)[i])
		i++;
	if (ft_isquote((*str)[0]))
		res = ft_substr(*str, 1, i - 2);
	else
		res = ft_substr(*str, 0, i);
	(*str) += i + 1;
	return (res);
}

void	move_to_next_token(char **str)
{
	(*str)++;
	while (**str)
		(*str)++;
	(*str)++;
}

int	io_error(t_pipex *pipex, char *file, int errnum)
{
	pipex->status = 0;
	if (errnum == 1 || errnum == 3)
		print_stderr("bash: ", ": No such file or directory", file);
	else if (errnum == 2)
		print_stderr("bash: ", ": permission denied", file);
	return (FAIL);
}

void	dup_file(t_pipex *pipex, char *file, int num)
{
	if (num == 0)
	{
		if (pipex->dupin > 0)
			close(pipex->dupin);
		pipex->dupin = open(file, O_RDONLY);
		dup2(pipex->dupin, STDIN_FILENO);
	}
	else if (num == 1)
	{
		if (pipex->dupout > 0)
			close(pipex->dupout);
		pipex->dupout = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		dup2(pipex->dupout, STDOUT_FILENO);
	}
	else
	{
		if (pipex->dupout > 0)
			close(pipex->dupout);
		pipex->dupout = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
		dup2(pipex->dupout, STDOUT_FILENO);
	}
}

void	reset_pipex(t_pipex *pipex)
{
	pipex->dupin = -2;
	pipex->dupout = -2;
	pipex->status = 1;
	pipex->exit = 0;
	pipex->is_pipe = 1;
	pipex->is_heredoc = 0;
}
