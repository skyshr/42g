/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:34:12 by jajo              #+#    #+#             */
/*   Updated: 2024/06/28 18:30:17 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_append(t_treenode *dest, t_treenode *src)
{
	int	i;
	int	size;

	i = -1;
	size = dest->arg_count + src->arg_count;
	dest->arguments = ft_realloc(dest->arguments, size);
	while (++i < src->arg_count)
	{
		dest->arguments[dest->arg_count] = ft_par_strdup(src->arguments[i]);
		free(src->arguments[i]);
		src->arguments[i] = NULL;
		dest->arg_count += 1;
	}
	src->arg_count = 0;
}

char	**ft_realloc(char **memblock, size_t size)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		error(4);
	ft_memset(tmp, 0, sizeof(char *) * (size + 1));
	if (!tmp)
		return (NULL);
	if (!memblock)
		return (tmp);
	else
	{
		while (memblock[++i])
		{
			tmp[i] = ft_par_strdup(memblock[i]);
			free(memblock[i]);
			memblock[i] = NULL;
		}
	}
	free(memblock);
	memblock = NULL;
	return (tmp);
}

char	*ft_par_strdup(const char *s)
{
	char		*dest;
	size_t		m;

	if (!s)
		return (NULL);
	m = ft_strlen(s);
	dest = (char *)malloc((m + 1) * sizeof(char));
	if (!dest)
		error(4);
	ft_strlcpy(dest, s, m + 1);
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
