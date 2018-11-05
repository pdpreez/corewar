/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 07:11:43 by swilson           #+#    #+#             */
/*   Updated: 2018/05/24 13:10:36 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*space;
	size_t	i;

	if (size <= 0)
		return (NULL);
	i = 0;
	if (!(space = (char*)malloc(size)))
		return (NULL);
	while (i < size)
	{
		space[i] = '\0';
		i++;
	}
	return (space);
}
