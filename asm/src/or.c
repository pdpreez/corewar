/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:27:35 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 13:53:22 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		get_or_opt_code(char *str, int fd)
{
	int		i;
	int		j;
	int		n;

	n = 7;
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

void		or_arg1(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
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

void		or_arg2(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
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

void		or_arg3(char *str, int fd)
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

void		or(char *str, int fd)
{
	get_or_opt_code(str, fd);
	or_arg1(str, fd);
	or_arg2(str, fd);
	or_arg3(str, fd);
}
