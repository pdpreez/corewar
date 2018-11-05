/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:56:42 by swilson           #+#    #+#             */
/*   Updated: 2018/05/24 13:17:55 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*local_s;
	unsigned char	local_c;

	i = 0;
	local_s = (unsigned char *)s;
	local_c = (unsigned char)c;
	while (i < n)
	{
		if (local_s[i] == local_c)
			return ((unsigned char*)s + i);
		i++;
	}
	return (NULL);
}
