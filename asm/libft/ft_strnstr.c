/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:07:52 by swilson           #+#    #+#             */
/*   Updated: 2018/05/24 14:55:17 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *h, const char *n, size_t c)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	if (n[i] == '\0')
		return ((char *)h);
	len = ft_strlen(n);
	while ((h[i] != '\0') && (c >= len))
	{
		j = 0;
		if ((h[i] == n[j]) && (ft_memcmp(h + i, n, len) == 0))
		{
			return ((char *)h + i);
		}
		i++;
		c--;
	}
	return (NULL);
}
