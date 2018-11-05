/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:35:22 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/28 11:40:09 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		store_core_int_4(int number, int fd)
{
	char	*num;
	char	prog[4];

	num = (char *)(&number);
	prog[0] = num[3];
	prog[1] = num[2];
	prog[2] = num[1];
	prog[3] = num[0];
	write(fd, prog, 4);
}

void		store_core_int_2(int number, int fd)
{
	char	*num;
	char	prog[2];

	num = (char *)(&number);
	prog[0] = num[1];
	prog[1] = num[0];
	write(fd, prog, 2);
}

void		live(char *str, int fd)
{
	long long		n;
	int				i;

	n = 1;
	i = 0;
	write(fd, &n, 1);
	while (str[i] && str[i] != '%')
		i++;
	i++;
	n = long_atoi(&str[i]);
	n = clean_value(n);
	store_core_int_4(n, fd);
}
