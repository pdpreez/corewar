/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:45:09 by swilson           #+#    #+#             */
/*   Updated: 2018/05/31 14:44:07 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*l_s1;
	unsigned char	*l_s2;
	size_t			i;

	if (n == 0)
		return (0);
	l_s1 = (unsigned char*)s1;
	l_s2 = (unsigned char*)s2;
	i = 0;
	while ((l_s1[i] == l_s2[i]) && (i < n - 1) && \
			(s1[i] != '\0') && (s2[i] != '\0'))
	{
		i++;
	}
	return (l_s1[i] - l_s2[i]);
}
