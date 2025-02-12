/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:35:13 by ksuh              #+#    #+#             */
/*   Updated: 2024/04/29 21:35:15 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid_base(char *base);
static int	find_index(char *base, char c);
static int	convert_from_base(char *str, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int		res;
	int		sign;
	size_t	i;

	if (!is_valid_base(base))
		return (0);
	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (str[i] == '0')
	{
		i++;
		if (str[i] == 'x')
			i++;
	}
	res = convert_from_base(&str[i], base);
	return (res * sign);
}

int	is_valid_base(char *base)
{
	size_t	i;
	size_t	j;
	size_t	base_len;

	base_len = ft_strlen(base);
	i = 0;
	while (i < base_len)
	{
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_index(char *base, char c)
{
	char	lower;
	int		i;

	lower = ft_tolower(c);
	i = 0;
	while (base[i])
	{
		if (base[i] == lower)
			return (i);
		i++;
	}
	return (-1);
}

int	convert_from_base(char *str, char *base)
{
	size_t	i;
	size_t	base_len;
	int		idx;
	int		res;

	i = 0;
	base_len = ft_strlen(base);
	while (str[i])
	{
		idx = find_index(base, str[i]);
		if (idx == -1)
			break ;
		res = res * base_len + idx;
		i++;
	}
	return (res);
}
