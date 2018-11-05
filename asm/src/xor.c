/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:18:53 by fledwaba          #+#    #+#             */
/*   Updated: 2018/11/05 11:51:06 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			get_xor_opt_code(char *str, int fd)
{
	int		i;
	int		j;
	int		n;

	n = 8;
	write(fd, &n, 1);
	i = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	j = i;
	while (str[j] != ',')
		j++;
	while (str[j] && str[j] != 'r' && str[j] != '%' && !ft_isdigit(str[j]))
		j++;
	n = check_encoding_byte(str, i, j);
	write(fd, &n, 1);
}

void			xor_arg1(char *str, int fd)
{
	int			i;
	long long	n;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i])
			&& str[i] != '-')
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '-')
		n = long_atoi(&str[i + 1]);
	else
		n = long_atoi(&str[i]);
	if (get_byte_no(str[i]) == 2)
		store_core_int_2(n, fd);
	else if (get_byte_no(str[i]) == 4)
		store_core_int_4(n, fd);
	else
		write(fd, &n, 1);
}

void			xor_arg2(char *str, int fd)
{
	int			i;
	long long	n;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i])
			&& str[i] != '-')
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '-')
		n = long_atoi(&str[i + 1]);
	else
		n = long_atoi(&str[i]);
	n = clean_value(n);
	if (get_byte_no(str[i]) == 2)
		store_core_int_2(n, fd);
	else if (get_byte_no(str[i]) == 4)
		store_core_int_4(n, fd);
	else
		write(fd, &n, 1);
}

void			xor_arg3(char *str, int fd)
{
	int			i;
	long long	n;

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

void			xor(char *str, int fd)
{
	get_xor_opt_code(str, fd);
	xor_arg1(str, fd);
	xor_arg2(str, fd);
	xor_arg3(str, fd);
}
