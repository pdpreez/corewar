/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:00:08 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/28 11:39:43 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		lld_n(char *str, int i, int fd)
{
	long long		n;

	i++;
	n = 13;
	write(fd, &n, 1);
	n = 144;
	write(fd, &n, 1);
	n = long_atoi(&str[i]);
	n = clean_value(n);
	store_core_int_4(n, fd);
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	write(fd, &n, 1);
}

void		lld_no(char *str, int i, int fd)
{
	long long		n;

	n = 13;
	write(fd, &n, 1);
	n = 208;
	write(fd, &n, 1);
	n = long_atoi(&str[i]);
	n = clean_value(n);
	store_core_int_2(n, fd);
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	write(fd, &n, 1);
}

void		lld(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	if (str[i] == '%')
		lld_n(str, i, fd);
	else
		lld_no(str, i, fd);
}
