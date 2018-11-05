/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:21:25 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/21 15:56:26 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		ft_lfork(char *str, int fd)
{
	int				i;
	long long		n;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (str[i] == '\0')
		return ;
	i++;
	n = 15;
	write(fd, &n, 1);
	n = long_atoi(&str[i]);
	n = clean_value(n);
	store_core_int_2(n, fd);
}
