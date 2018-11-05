/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:39:37 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 13:43:29 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		ld_n(char *str, int i, int fd)
{
	long long		n;

	i++;
	n = 2;
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

void		ld_no(char *str, int i, int fd)
{
	long long		n;

	n = 2;
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

void		ld(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	if (str[i] == '%')
		ld_n(str, i, fd);
	else
		ld_no(str, i, fd);
}
