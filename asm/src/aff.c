/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:27:30 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/12 13:15:36 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		aff(char *str, int fd)
{
	int				i;
	long long		n;

	i = 0;
	while (str[i] && str[i] != 'r')
		i++;
	if (str[i] == '\0')
		return ;
	i++;
	n = 16;
	write(fd, &n, 1);
	n = 64;
	write(fd, &n, 1);
	n = long_atoi(&str[i]);
	n = clean_value(n);
	write(fd, &n, 1);
}
