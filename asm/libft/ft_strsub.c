/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:20:04 by swilson           #+#    #+#             */
/*   Updated: 2018/05/24 14:56:10 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;
	char	*str;

	if (!s)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = start;
	j = 0;
	str = (char*)s;
	while (j < len)
	{
		ret[j] = str[j + i];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
