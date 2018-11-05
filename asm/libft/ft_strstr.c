/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:51:47 by swilson           #+#    #+#             */
/*   Updated: 2018/05/21 14:52:18 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strstr(const char *h, const char *n)
{
	int i;

	i = 0;
	if (n[i] == '\0')
		return ((char *)h);
	while ((h[i] != '\0') && (n[0] != '\0'))
	{
		if (h[i] == n[0])
		{
			if (ft_memcmp(h + i, n, ft_strlen(n)) == 0)
			{
				return ((char *)h + i);
			}
		}
		i++;
	}
	return (NULL);
}
