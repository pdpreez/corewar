/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_byte_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:39:33 by fledwaba          #+#    #+#             */
/*   Updated: 2018/11/05 11:42:36 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			get_byte_no(char c)
{
	if (c == '%')
		return (4);
	else if (ft_isdigit(c) || c == '-')
		return (2);
	else if (c == 'r')
		return (1);
	else
		return (-1);
}

int			i_byte_no(char c)
{
	if (c == '%')
		return (2);
	else if (ft_isdigit(c) || c == '-')
		return (2);
	else if (c == 'r')
		return (1);
	else
		return (-1);
}
