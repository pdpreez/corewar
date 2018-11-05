/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:57:29 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 12:39:55 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			zjmp(char *str, int fd)
{
	int				i;
	long long		n;

	n = 9;
	write(fd, &n, 1);
	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (str[i] == '\0')
		return ;
	i++;
	n = long_atoi(&str[i]);
	n = clean_value(n);
	store_core_int_2(n, fd);
}
