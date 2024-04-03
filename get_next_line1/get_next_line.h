/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:10:32 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/18 13:05:25 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

size_t	get_read_bytes(char *lst, int *is_end);
char	*read_buffer(int fd, char *lst, char *buffer, int *is_end);
char	*strjoin(char *src1, char *src2, size_t bytesize);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
void	reset(char *lst, size_t readbytes);

#endif
