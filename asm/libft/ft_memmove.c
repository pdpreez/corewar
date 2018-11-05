/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:25:36 by swilson           #+#    #+#             */
/*   Updated: 2018/05/25 10:36:10 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*local_dest;
	char	*local_src;

	local_dest = (char*)dest;
	local_src = (char*)src;
	i = 0;
	if (local_src < local_dest)
	{
		while (n--)
			local_dest[n] = local_src[n];
	}
	else
	{
		while (i < n)
		{
			local_dest[i] = local_src[i];
			i++;
		}
	}
	return (dest);
}
