/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:28:51 by ksuh              #+#    #+#             */
/*   Updated: 2024/05/20 14:14:25 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*back;

	if (lst == NULL || new == NULL)
		return (1);
	back = ft_lstlast(*lst);
	if (back)
		back->next = new;
	else
		*lst = new;
	return (0);
}
