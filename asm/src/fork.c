/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:40:29 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/12 13:29:02 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		ft_fork(char *str, int fd)
{
	int				i;
	long long		n;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (str[i] == '\0')
		return ;
	i++;
	n = 12;
	write(fd, &n, 1);
	n = long_atoi(&str[i]);
	n = clean_value(n);
	store_core_int_2(n, fd);
}
