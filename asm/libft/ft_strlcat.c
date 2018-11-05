/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:38:46 by swilson           #+#    #+#             */
/*   Updated: 2018/05/28 13:54:55 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	char	*lsrc;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	lsrc = (char*)src;
	i = 0;
	if (dest_len > n)
		return (n + src_len);
	else
	{
		while ((lsrc[i] != '\0') && ((dest_len + i) < (n - 1)))
		{
			dest[dest_len + i] = lsrc[i];
			i++;
		}
		dest[dest_len + i] = '\0';
	}
	return (dest_len + src_len);
}
