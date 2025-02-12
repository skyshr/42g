/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:32:39 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/26 18:17:51 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_parenthesis_validation(char **str, int *br);
static void	process_seperator(char **str, int *pretoken, \
								int *curtoken, int *br);
static void	process_token(char **str, int *pretoken, int *curtoken, int *br);
static void	process_parenthesis(char **str, int *pretoken, \
									int *curtoken, int *br);

int	is_valid_parenthesis(char *str)
{
	int	br;

	if (str == NULL)
		return (0);
	br = 0;
	process_parenthesis_validation(&str, &br);
	if (*str == '\0' && *(str + 1) == '\0' && br == 0)
		return (1);
	ft_putendl_fd("bash: syntax error: parenthesis unmatch", STDERR_FILENO);
	return (0);
}

void	process_parenthesis_validation(char **str, int *br)
{
	int		pretoken;
	int		curtoken;

	pretoken = 0;
	curtoken = 0;
	while ((**str || *(*str + 1)) && *br >= 0)
	{
		if (**str == '\0' || **str == '|' || **str == '&' \
			|| ft_isredirection(**str))
			process_seperator(str, &pretoken, &curtoken, br);
		else if (**str == 34)
			process_token(str, &pretoken, &curtoken, br);
		else
			process_parenthesis(str, &pretoken, &curtoken, br);
	}
}

void	process_seperator(char **str, int *pretoken, int *curtoken, int *br)
{
	if (ft_isredirection(**str))
	{
		if (*pretoken == 5)
		{
			(*br) = -1;
			return ;
		}
		while (!ft_isquote(**str))
			(*str)++;
		process_token(str, pretoken, curtoken, br);
		return ;
	}
	*pretoken = *curtoken;
	if (**str == '\0')
	{
		*curtoken = 1;
		(*str)++;
	}
	else if (**str == '|' || **str == '&')
	{
		*curtoken = 2;
		while (**str)
			(*str)++;
	}
}

void	process_token(char **str, int *pretoken, int *curtoken, int *br)
{
	if (*pretoken == 5 && *curtoken == 1)
	{
		*br = -1;
		return ;
	}
	else
	{
		*pretoken = *curtoken;
		*curtoken = 3;
		while (**str)
			(*str)++;
	}
}

void	process_parenthesis(char **str, int *pretoken, int *curtoken, int *br)
{
	if (**str == '(')
	{
		if (*curtoken == 5 || (*curtoken == 1 \
			&& (*pretoken == 5 || *pretoken == 3)))
		{
			(*br) = -1;
			return ;
		}
		*pretoken = *curtoken;
		*curtoken = 4;
		(*br)++;
		(*str)++;
	}
	else
	{
		if (*curtoken == 4 || (*curtoken == 1 && *pretoken == 4))
		{
			(*br) = -1;
			return ;
		}
		*pretoken = *curtoken;
		*curtoken = 5;
		(*br)--;
		(*str)++;
	}
}
