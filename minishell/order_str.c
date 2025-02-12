/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:09:54 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/27 13:03:51 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_total_len(char *str);
static void	copy_parenthesis(char *dest, char *src);
static int	move_parenthesis(char **str);
static void	copy_cmds(char **str, char *dest, char *tmp, int *i);

char	*order_str(char *str)
{
	int		len;
	int		i;
	char	*dest;

	len = get_total_len(str);
	dest = (char *)malloc(len * sizeof(char));
	if (dest == NULL)
		error(4);
	(ft_memset(dest, 0, len), copy_parenthesis(dest, str));
	i = 0;
	while (*str || *(str + 1))
	{
		if (ft_isparenthesis(*str))
			i += move_parenthesis(&str);
		else if (*str == '|' || *str == '&')
		{
			while (*str == '|' || *str == '&')
				dest[i++] = *str++;
			if (*(str + 1))
				dest[i++] = *str++;
		}
		else
			copy_cmds(&str, dest, NULL, &i);
	}
	return (dest);
}

int	get_total_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] || str[i + 1])
		i++;
	return (i + 2);
}

void	copy_parenthesis(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] || src[i + 1])
	{
		if (ft_isparenthesis(src[i]))
		{
			while (ft_isparenthesis(src[i]))
			{
				dest[i] = src[i];
				i++;
			}
			if (src[i + 1])
			{
				dest[i] = src[i];
				i++;
			}
		}
		else
			i++;
	}
	dest[i++] = '\0';
	dest[i] = '\0';
}

int	move_parenthesis(char **str)
{
	int	i;

	i = 0;
	while (ft_isparenthesis(**str))
	{
		(*str)++;
		i++;
	}
	if (*(*str + 1))
	{
		(*str)++;
		i++;
	}
	return (i);
}

void	copy_cmds(char **str, char *dest, char *tmp, int *i)
{
	tmp = *str;
	while ((**str || *(*str + 1)) && !ft_isoperand(**str) \
			&& !ft_isparenthesis(**str))
	{
		if (ft_isredirection(**str))
		{
			while (**str)
				(*str)++;
			if (*(*str + 1))
				(*str)++;
		}
		else
			copy_str(str, dest, i);
	}
	while ((*tmp || *(tmp + 1)) && !ft_isoperand(*tmp) \
			&& !ft_isparenthesis(*tmp))
	{
		if (ft_isredirection(*tmp))
			copy_rdt(&tmp, dest, i);
		else
			tmp++;
	}
}
