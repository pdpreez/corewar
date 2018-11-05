/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:20:32 by swilson           #+#    #+#             */
/*   Updated: 2018/09/27 13:20:34 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinfree(char *str1, char *str2)
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
	free(str1);
	return (ret);
}
