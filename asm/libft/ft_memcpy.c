/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:39:43 by swilson           #+#    #+#             */
/*   Updated: 2018/05/23 09:24:52 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*local_dest;
	unsigned char	*local_src;

	i = 0;
	local_dest = (unsigned char *)dest;
	local_src = (unsigned char *)src;
	while (i < n)
	{
		local_dest[i] = local_src[i];
		i++;
	}
	return (dest);
}
