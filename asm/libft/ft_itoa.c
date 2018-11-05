/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:02:01 by swilson           #+#    #+#             */
/*   Updated: 2018/05/28 13:30:30 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count(int n)
{
	int len;
	int num;

	num = n;
	len = 1;
	while (num /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int num)
{
	int		len;
	int		sign;
	char	*ret;
	long	n;

	n = (long)num;
	sign = 0;
	len = count(n);
	if (n < 0)
		sign = 1;
	if (!(ret = (char*)malloc(sizeof(char) * len + sign + 1)))
		return (NULL);
	if (sign)
	{
		len += sign;
		ret[0] = '-';
		n *= -1;
	}
	ret[len] = '\0';
	ret[--len] = n % 10 + '0';
	while (n /= 10)
	{
		ret[--len] = n % 10 + '0';
	}
	return (ret);
}
