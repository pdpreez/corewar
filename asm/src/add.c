/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:33:56 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/26 17:46:49 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		get_add_arg1_value(char *str, int fd)
{
	int			i;
	long long	n;

	n = 4;
	write(fd, &n, 1);
	i = 84;
	write(fd, &i, 1);
	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	n = long_atoi(&str[i]);
	write(fd, &n, 1);
}

void		get_add_arg2_value(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	write(fd, &n, 1);
}

void		get_add_arg3_value(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	i++;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	write(fd, &n, 1);
}

void		add(char *str, int fd)
{
	get_add_arg1_value(str, fd);
	get_add_arg2_value(str, fd);
	get_add_arg3_value(str, fd);
}
