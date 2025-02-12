/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:33:33 by ksuh              #+#    #+#             */
/*   Updated: 2024/05/08 22:36:27 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	memlen(char *s, char c);
static char		*splitalloc(char **s, char c);
static void		splitfree(char ***dest, size_t idx);
static int		truncate_str(char *s);

char	**split(char *s, char c)
{
	char	**dest;
	size_t	len;
	size_t	destidx;

	len = memlen(s, c);
	dest = (char **)malloc((len + 1) * sizeof(char *));
	if (!dest)
		return (0);
	destidx = 0;
	while (destidx < len)
	{
		dest[destidx] = splitalloc(&s, c);
		if (!dest[destidx])
		{
			splitfree(&dest, destidx);
			return (0);
		}
		destidx++;
	}
	dest[destidx] = 0;
	return (dest);
}

void	splitfree(char ***dest, size_t idx)
{
	size_t	m;

	m = 0;
	while (m < idx)
		free(*dest[m++]);
	free(*dest);
}

char	*splitalloc(char **s, char c)
{
	size_t	m;
	char	*res;

	m = 0;
	while (**s && **s == c)
		(*s)++;
	if (**s == 34 || **s == 39)
	{
		m = truncate_str(*s);
		res = ft_substr(*s, 1, m - 2);
	}
	else
	{
		while (*(*s + m) && *(*s + m) != c)
			m++;
		res = ft_substr(*s, 0, m);
	}
	*s += m;
	return (res);
}

size_t	memlen(char *s, char c)
{
	size_t	m;

	m = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (*s == 34 || *s == 39)
				s += truncate_str(s);
			else
				while (*s && *s != c)
					s++;
			m++;
		}
	}
	return (m);
}

int	truncate_str(char *s)
{
	int	i;

	i = 1;
	while (s[i] != '\0')
	{
		if (s[0] == 34 && s[i - 1] != '\\' && s[i] == s[0] \
			&& (s[i + 1] == '\0' || s[i + 1] == ' '))
			return (i + 1);
		else if (s[0] == 39 && s[i] == s[0] && \
			(s[i + 1] == '\0' || s[i + 1] == ' '))
			return (i + 1);
		i++;
	}
	return (i);
}
