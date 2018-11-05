/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:34:58 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 13:54:12 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		st_op_code(char *str, int fd)
{
	int		i;
	int		n;

	n = 3;
	write(fd, &n, 1);
	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r' && !ft_isdigit(str[i]))
		i++;
	if (str[i] == 'r')
		n = 80;
	else
		n = 112;
	write(fd, &n, 1);
}

void		st_arg1(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	write(fd, &n, 1);
}

void		st_arg2(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && !ft_isdigit(str[i]) && str[i] != 'r')
		i++;
	if (str[i] != 'r')
		n = long_atoi(&str[i]);
	else
		n = long_atoi(&str[i + 1]);
	if (get_byte_no(str[i]) == 2)
		store_core_int_2(n, fd);
	else
		write(fd, &n, 1);
}

void		st(char *str, int fd)
{
	st_op_code(str, fd);
	st_arg1(str, fd);
	st_arg2(str, fd);
}
