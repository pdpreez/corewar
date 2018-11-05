/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:42:43 by swilson           #+#    #+#             */
/*   Updated: 2018/05/29 07:16:15 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\0') || (c == '\n') || (c == '\v') ||\
			(c == '\t') || (c == '\r') || (c == '\f'))
	{
		return (1);
	}
	return (0);
}

static	int	getsize(char *str, int *i, int *len)
{
	while (((ft_isspace(str[*i])) || (ft_isspace(str[*len]))) && (*i <= *len))
	{
		if (ft_isspace(str[*i]))
			(*i)++;
		if (ft_isspace(str[*len]))
			(*len)--;
	}
	return (*len -= *i);
}

char		*ft_strtrim(const char *s)
{
	char	*ret;
	char	*str;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	str = (char*)s;
	len = ft_strlen(str);
	j = 0;
	i = 0;
	len = getsize(str, &i, &len);
	if (!(ret = (char*)malloc(sizeof(char) * len + 2)))
		return (NULL);
	j -= 1;
	while (++j <= len)
		ret[j] = str[i + j];
	ret[j] = '\0';
	return (ret);
}
