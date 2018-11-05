/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:37:42 by swilson           #+#    #+#             */
/*   Updated: 2018/05/24 13:17:07 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
