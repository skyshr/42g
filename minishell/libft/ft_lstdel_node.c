/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:29:10 by ksuh              #+#    #+#             */
/*   Updated: 2024/05/27 16:46:27 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_node(t_env **lst, t_env *prev, t_env *cur)
{
	if (prev)
		prev->next = cur->next;
	else
		*lst = cur->next;
	free(cur->name);
	free(cur->value);
	free(cur);
}
