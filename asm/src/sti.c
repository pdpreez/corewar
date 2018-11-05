/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:34:35 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 13:55:34 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		get_sti_opt_code(char *str, int fd)
{
	int		i;
	int		j;
	int		n;

	n = 11;
	write(fd, &n, 1);
	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%' && !ft_isdigit(str[i]))
		i++;
	j = i;
	while (str[j] != ',')
		j++;
	while (str[j] && str[j] != 'r' && str[j] != '%' && !ft_isdigit(str[j]))
		j++;
	n = check_sti(str, i, j);
	write(fd, &n, 1);
}

void		sti_arg1(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && str[i] != 'r')
		i++;
	i++;
	n = long_atoi(&str[i]);
	n = clean_value(n);
	write(fd, &n, 1);
}

void		sti_arg2(char *str, int fd)
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
	if (i_byte_no(str[i]) == 2)
		store_core_int_2(n, fd);
	else
		write(fd, &n, 1);
}

void		sti_arg3(char *str, int fd)
{
	long long	n;
	int			i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	i++;
	while (str[i] && str[i] != ',')
		i++;
	while (str[i] && str[i] != 'r' && str[i] != '%')
		i++;
	n = long_atoi(&str[i + 1]);
	n = clean_value(n);
	if (i_byte_no(str[i]) == 2)
		store_core_int_2(n, fd);
	else
		write(fd, &n, 1);
}

void		sti(char *str, int fd)
{
	get_sti_opt_code(str, fd);
	sti_arg1(str, fd);
	sti_arg2(str, fd);
	sti_arg3(str, fd);
}
