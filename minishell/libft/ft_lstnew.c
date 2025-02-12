/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:01:45 by ksuh              #+#    #+#             */
/*   Updated: 2024/05/27 15:02:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_env	*ft_lstnew(char *name, char *value)
{
	t_env	*lst;

	lst = (t_env *)malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->name = name;
	lst->value = value;
	lst->status = 1;
	lst->next = NULL;
	return (lst);
}
