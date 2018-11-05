/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:02:40 by swilson           #+#    #+#             */
/*   Updated: 2018/06/04 09:34:06 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *node, void (*f)(t_list *elem))
{
	if (node || f)
	{
		while (node)
		{
			f(node);
			node = node->next;
		}
	}
	return ;
}
