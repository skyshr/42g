/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:42:54 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/24 16:28:59 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_file_error(char *error_msg, char *filename)
{
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putendl_fd(filename, STDERR_FILENO);
}

void	error(int error_num)
{
	if (error_num == 1)
	{
		ft_putstr_fd("usage: ./pipex infile \"cmd1\"", STDERR_FILENO);
		ft_putendl_fd(" \"cmd2\" outfile", STDERR_FILENO);
	}
	else if (error_num == 2)
		ft_putendl_fd("pipe() value returned -1", STDERR_FILENO);
	else if (error_num == 3)
		ft_putendl_fd("fork() value returned -1", STDERR_FILENO);
	else if (error_num == 4)
		ft_putendl_fd("split error", STDERR_FILENO);
	exit(error_num);
}
