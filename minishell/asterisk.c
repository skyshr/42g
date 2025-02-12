/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 07:55:34 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/26 21:59:37 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_astk_len(char *str, char **dirs);
static int	get_astk_tr_len(char **str, char **dirs);
static void	astk_cpy(char *dest, char *src, char **dirs);
static void	astk_tr_cpy(char **dest, char **src, char **dirs);

char	*translate_asterisk(char *str)
{
	char	*res;
	char	*pwd;
	char	**dirs;
	int		len;

	pwd = get_pwd();
	dirs = get_dir(pwd);
	len = get_astk_len(str, dirs);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		error(4);
	ft_memset(res, 0, len + 1);
	astk_cpy(res, str, dirs);
	free_args(dirs);
	free(pwd);
	return (res);
}

int	get_astk_len(char *str, char **dirs)
{
	int	len;

	len = 0;
	while (*str != '\0' || *(str + 1) != '\0')
	{
		if (*str == 34 && *(str + 1) == 34)
		{
			while (*str++)
				len++;
		}
		else if (*str == 34 && ft_strchr(str, '*'))
			len += get_astk_tr_len(&str, dirs);
		else
		{
			str++;
			len++;
		}
	}
	return (len + 2);
}

int	get_astk_tr_len(char **str, char **dirs)
{
	int		len;
	int		total_len;
	char	*pattern;

	len = ft_strlen(*str) - 2;
	pattern = (char *)malloc((len + 1) * sizeof(char));
	ft_strlcpy(pattern, *str + 1, len + 1);
	total_len = get_matched_file_len(pattern, dirs);
	free(pattern);
	*str += len + 2;
	if (total_len == 0)
		return (len + 2);
	return (total_len);
}

void	astk_cpy(char *dest, char *src, char **dirs)
{
	while (*src != '\0' || *(src + 1) != '\0')
	{
		if (*src == 34 && ft_strchr(src, '*'))
			astk_tr_cpy(&dest, &src, dirs);
		else if (*src == 34)
		{
			while (*src)
				*dest++ = *src++;
		}
		else
			*dest++ = *src++;
	}
	*dest++ = '\0';
	*dest = '\0';
}

void	astk_tr_cpy(char **dest, char **src, char **dirs)
{
	int		len;
	char	*pattern;
	char	*ptr;

	ptr = *dest;
	len = ft_strlen(*src) - 2;
	pattern = (char *)malloc((len + 1) * sizeof(char));
	if (pattern == NULL)
		error(4);
	ft_strlcpy(pattern, *src + 1, len + 1);
	concat_matched_files(dest, dirs, pattern);
	free(pattern);
	if (*dest == ptr)
	{
		ft_strlcpy(*dest, *src, len + 3);
		*dest += len + 3;
	}
	*src += len + 3;
}
