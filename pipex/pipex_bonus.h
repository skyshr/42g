/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:54:45 by ksuh              #+#    #+#             */
/*   Updated: 2024/05/08 21:34:39 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define HEREDOC_ERROR "Wrong usage: Usage: here_doc LIMITER cmd cmd1 file"

typedef struct s_pipex
{
	int	fdin;
	int	fdout;
	int	dupin;
	int	dupout;
	int	status;
}	t_pipex;

void	error(int error_num);
char	*get_command_path(char *pathname, char **envp);
void	print_file_error(char *error_msg, char *filename);
void	heredoc(t_pipex *pipex, char **argv, char **envp);
void	handle_file_errors(t_pipex *pipex, char *infile, char *outfile);
void	redirect(char *cmd, char **envp, int n);
void	execute(char *cmd, char **envp);
void	free_data(char **sp, char *path, int error_num);
void	redirect_end(t_pipex *pipex, char *cmd, char *outfile, char **envp);
void	wait_child(t_pipex *pipex, int child_count);
char	**split(char *s, char c);

#endif