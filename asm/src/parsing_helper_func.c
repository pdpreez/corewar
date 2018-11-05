/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:48:54 by swilson           #+#    #+#             */
/*   Updated: 2018/09/28 11:11:39 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdlib.h>

int	check_direct(char *str, t_asm_list *labels)
{
	int sign;

	sign = 0;
	if ((str[0] == '%') && (str[1] == LABEL_CHAR))
	{
		if (is_valid_label(str + 2, labels))
			return (1);
	}
	else if ((str[0] == '%') && (ft_isdigit(str[1]) || str[1] == '-'))
	{
		if (str[1] == '-')
			sign++;
		if (is_valid_nbr(str + 1, sign))
			return (1);
	}
	return (0);
}

int	check_r_d_i(char *str, t_asm_list *labels)
{
	if (check_register(str))
		return (1);
	if (check_direct(str, labels))
		return (2);
	else if (check_indirect(str))
		return (3);
	return (0);
}

int	check_r_d(char *str, t_asm_list *labels)
{
	if (check_register(str))
		return (1);
	else if (check_direct(str, labels))
		return (2);
	return (0);
}

int	check_r_i(char *str)
{
	if (check_register(str))
		return (1);
	else if (check_indirect(str))
		return (2);
	return (0);
}

int	check_d_i(char *str, t_asm_list *labels)
{
	if (check_direct(str, labels))
		return (1);
	if (check_indirect(str))
		return (2);
	return (0);
}
