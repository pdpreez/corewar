/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:34:19 by swilson           #+#    #+#             */
/*   Updated: 2018/06/04 10:46:28 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *node, t_list *(*f)(t_list *elem))
{
	t_list *cnode;
	t_list *hnode;

	if (!(cnode = f(node)))
	{
		free(cnode);
		return (NULL);
	}
	hnode = cnode;
	while (node->next)
	{
		node = node->next;
		if (!(cnode->next = f(node)))
		{
			free(cnode->next);
			return (NULL);
		}
		cnode = cnode->next;
	}
	cnode->next = NULL;
	return (hnode);
}
