/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:26:11 by fledwaba          #+#    #+#             */
/*   Updated: 2018/11/05 11:48:58 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		get_ldi_opt_code(char *str, int fd)
{
	int		i;
	int		j;
	int		n;

	n = 10;
	write(fd, &n, 1);
	i = 0;
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

void		ldi_arg1(char *str, int fd)
{
	long long		n;
	int				i;

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
	n = clean_value(n);
	if (i_byte_no(str[i]) == 2)
		store_core_int_2(n, fd);
	else
		write(fd, &n, 1);
}

void		ldi_arg2(char *str, int fd)
{
	long long		n;
	int				i;

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
	if (i_byte_no(str[i]) == 2)
		store_core_int_2(n, fd);
	else
		write(fd, &n, 1);
}

void		ldi_arg3(char *str, int fd)
{
	long long		n;
	int				i;

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

void		ldi(char *str, int fd)
{
	get_ldi_opt_code(str, fd);
	ldi_arg1(str, fd);
	ldi_arg2(str, fd);
	ldi_arg3(str, fd);
}
