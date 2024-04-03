/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:06:47 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/23 12:58:05 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	backup[BUFFER_SIZE];
	char		*buffer;
	int			is_end;

	is_end = 0;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup[0] == '\0' && read(fd, backup, BUFFER_SIZE) <= 0)
		return (NULL);
	buffer = NULL;
	while (!is_end)
		buffer = read_buffer(fd, backup, buffer, &is_end);
	return (buffer);
}
