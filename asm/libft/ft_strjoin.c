/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:33:40 by swilson           #+#    #+#             */
/*   Updated: 2018/06/01 08:21:05 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	if (!str1 || !str2)
		return (NULL);
	i = -1;
	j = -1;
	len = ft_strlen((char*)str1) + ft_strlen((char*)str2);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while ((char)str1[++i] != '\0')
		ret[i] = (char)str1[i];
	while ((char)str2[++j] != '\0')
		ret[i + j] = (char)str2[j];
	ret[i + j] = '\0';
	return (ret);
}
