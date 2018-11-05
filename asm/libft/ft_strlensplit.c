/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlensplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 08:16:42 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/28 08:17:09 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	split(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && (s[i] != '\0'))
		{
			count++;
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
		}
	}
	return (count);
}

static char	**make_string(char *s, int count, char **ret, char c)
{
	int i;
	int k;
	int j;

	i = 0;
	j = 0;
	while (i < (count))
	{
		if (s[j] != c && s[j] != '\0')
		{
			k = 0;
			while (s[j + k] != '\0' && s[j + k] != c)
			{
				k++;
			}
			ret[i] = ft_strsub(s, j, k);
			j += k;
			i++;
		}
		else
			j++;
	}
	return (ret);
}
