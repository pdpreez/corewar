/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:34:20 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 13:54:34 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		get_sub_op_code(int fd)
{
	int		n;

	n = 5;
	write(fd, &n, 1);
	n = 84;
	write(fd, &n, 1);
}

void		sub_arg1(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	n = long_atoi(&str[i]);
	write(fd, &n, 1);
}

void		sub_arg2(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	n = long_atoi(&str[i]);
	write(fd, &n, 1);
}

void		sub_arg3(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	i++;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	n = long_atoi(&str[i]);
	write(fd, &n, 1);
}

void		sub(char *str, int fd)
{
	get_sub_op_code(fd);
	sub_arg1(str, fd);
	sub_arg2(str, fd);
	sub_arg3(str, fd);
}
