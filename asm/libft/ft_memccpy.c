/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:11:22 by swilson           #+#    #+#             */
/*   Updated: 2018/05/29 11:34:55 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*local_dest;
	unsigned char	*local_src;
	unsigned char	local_c;

	local_dest = (unsigned char *)dest;
	local_src = (unsigned char *)src;
	local_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		local_dest[i] = local_src[i];
		if (local_src[i] == local_c)
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
