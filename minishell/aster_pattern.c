/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aster_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:13:24 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/26 08:24:12 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_match(char *pattern, char *file)
{
	if (*pattern == '\0' && *file == '\0')
		return (1);
	if (*pattern == '*')
	{
		while (*pattern == '*')
			pattern++;
		while (*file)
		{
			while (*file && *file != *pattern)
				file++;
			if (is_match(pattern, file))
				return (1);
			file++;
		}
		return (is_match(pattern, file));
	}
	if (*pattern == '\0' || *file == '\0')
		return (0);
	if (*pattern != *file)
		return (0);
	return (is_match(++pattern, ++file));
}

void	concat_matched_files(char **dest, char **dirs, char *pattern)
{
	int	len;

	if (dirs == NULL || *dirs == NULL)
		return ;
	if (is_match(pattern, *dirs))
	{
		len = ft_strlen(*dirs);
		*(*dest)++ = 34;
		ft_strlcpy(*dest, *dirs, len + 1);
		(*dest) += len;
		*(*dest)++ = 34;
		*(*dest)++ = '\0';
	}
	concat_matched_files(dest, ++dirs, pattern);
}
