/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:00:35 by swilson           #+#    #+#             */
/*   Updated: 2018/06/04 08:41:54 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **node, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!*node || !del)
		return ;
	while (*node)
	{
		temp = (*node)->next;
		del((*node)->content, (*node)->content_size);
		free(*node);
		*node = temp;
	}
	*node = NULL;
}
