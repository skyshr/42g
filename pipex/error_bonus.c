/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:57:33 by ksuh              #+#    #+#             */
/*   Updated: 2024/05/08 20:51:46 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_file_error(char *error_msg, char *filename)
{
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putendl_fd(filename, STDERR_FILENO);
}

void	error(int error_num)
{
	if (error_num == 1)
		ft_putendl_fd("Give more than 4 arguments.", STDERR_FILENO);
	else if (error_num == 2)
		ft_putendl_fd("pipe() value returned -1.", STDERR_FILENO);
	else if (error_num == 3)
		ft_putendl_fd("fork() value returned -1.", STDERR_FILENO);
	else if (error_num == 4)
		ft_putendl_fd("split error.", STDERR_FILENO);
	else if (error_num == 5)
		ft_putendl_fd(HEREDOC_ERROR, STDERR_FILENO);
	exit(error_num);
}

void	handle_file_errors(t_pipex *pipex, char *infile, char *outfile)
{
	pipex->fdin = access(infile, F_OK);
	if (pipex->fdin == -1)
		print_file_error("zsh: no such file or directory: ", infile);
	else
	{
		pipex->fdin = open(infile, O_RDONLY);
		if (pipex->fdin == -1)
			print_file_error("zsh: permission denied: ", infile);
	}
	pipex->fdout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}
