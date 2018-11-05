/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:14:13 by swilson           #+#    #+#             */
/*   Updated: 2018/05/29 12:15:49 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*local_s1;
	unsigned char	*local_s2;

	i = 0;
	local_s1 = (unsigned char *)s1;
	local_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (local_s1[i] != local_s2[i])
			return (local_s1[i] - local_s2[i]);
		i++;
	}
	return (0);
}
