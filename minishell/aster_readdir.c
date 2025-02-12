/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aster_readdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:13:06 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/26 21:37:58 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_dir_len(char *pwd);
static char	**get_dir_data(DIR *dir, char **res, int len);

char	**get_dir(char *pwd)
{
	DIR		*dir;
	char	**res;
	int		len;

	len = get_dir_len(pwd);
	dir = opendir(pwd);
	if (dir == NULL)
		error(6);
	res = (char **)malloc((len + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	return (get_dir_data(dir, res, len));
}

int	get_dir_len(char *pwd)
{
	DIR				*dir;
	struct dirent	*entry;
	int				dir_cnt;

	dir = opendir(pwd);
	if (dir == NULL)
		error(6);
	dir_cnt = 0;
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (entry->d_name[0] != '.')
			dir_cnt++;
	}
	closedir(dir);
	return (dir_cnt);
}

char	**get_dir_data(DIR *dir, char **res, int len)
{
	struct dirent	*entry;
	char			*data;
	int				i;
	int				j;

	i = 0;
	while (i < len)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		data = entry->d_name;
		if (!ft_strncmp(data, ".", 1))
			continue ;
		j = ft_strlen(data) + 1;
		res[i] = (char *)malloc(j * sizeof(char));
		if (res[i] == NULL)
			error(4);
		ft_strlcpy(res[i++], data, j);
	}
	res[i] = NULL;
	closedir(dir);
	return (res);
}

char	*get_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 1024);
	if (pwd == NULL)
		error(4);
	return (pwd);
}

int	get_matched_file_len(char *pattern, char **dirs)
{
	int	len;

	if (dirs == NULL || *dirs == NULL)
		return (0);
	len = get_matched_file_len(pattern, dirs + 1);
	if (is_match(pattern, *dirs))
		len += ft_strlen(*dirs) + 3;
	return (len);
}
