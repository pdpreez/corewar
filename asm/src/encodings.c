/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encodings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:38:33 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 13:38:56 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_sti(char *str, int i, int j)
{
	if (str[i] == '%' && str[j] == '%')
		return (104);
	else if (str[i] == '%' && str[j] == 'r')
		return (100);
	else if (ft_isdigit(str[i]) && str[j] == '%')
		return (120);
	else if (ft_isdigit(str[i]) && str[j] == 'r')
		return (116);
	else if (str[i] == 'r' && str[j] == '%')
		return (88);
	else if (str[i] == 'r' && str[j] == 'r')
		return (84);
	return (-1);
}

int			check_encoding_byte(char *str, int i, int j)
{
	if (str[i] == '%' && str[j] == '%')
		return (164);
	else if (str[i] == '%' && ft_isdigit(str[j]))
		return (180);
	else if (str[i] == '%' && str[j] == 'r')
		return (148);
	else if (ft_isdigit(str[i]) && str[j] == '%')
		return (228);
	else if (ft_isdigit(str[i]) && ft_isdigit(str[j]))
		return (244);
	else if (ft_isdigit(str[i]) && str[j] == 'r')
		return (212);
	else if (str[i] == 'r' && str[j] == '%')
		return (100);
	else if (str[i] == 'r' && ft_isdigit(str[j]))
		return (116);
	else if (str[i] == 'r' && str[j] == 'r')
		return (84);
	return (-1);
}
