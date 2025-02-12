/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:28:07 by ksuh              #+#    #+#             */
/*   Updated: 2024/05/08 21:34:32 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int	fdin;
	int	fdout;
	int	dupin;
	int	dupout;
}	t_pipex;

void	error(int error_num);
char	*get_command_path(char *pathname, char **envp);
void	print_file_error(char *error_msg, char *filename);
void	redirect_end(t_pipex *pipex, char *cmd, char *outfile, char **envp);
void	execute(char *cmd, char **envp);
char	**split(char *s, char c);

#endif