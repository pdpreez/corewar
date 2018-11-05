/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:36:03 by swilson           #+#    #+#             */
/*   Updated: 2018/06/04 09:01:44 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **node, t_list *newnode)
{
	if (*node || newnode)
	{
		newnode->next = *node;
		*node = newnode;
	}
	return ;
}
