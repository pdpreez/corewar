/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 07:47:11 by swilson           #+#    #+#             */
/*   Updated: 2018/05/22 07:49:32 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_strnew(size_t size)
{
	char	*space;
	size_t	i;

	i = 0;
	size++;
	if (!(space = (char*)malloc(size)))
		return (NULL);
	while (i < size)
	{
		space[i] = '\0';
		i++;
	}
	return (space);
}
