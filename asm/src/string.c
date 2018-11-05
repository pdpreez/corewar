/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:56:30 by swilson           #+#    #+#             */
/*   Updated: 2018/09/27 16:42:33 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdlib.h>

int	len_to_char(char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

int	is_white_space(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (1);
	return (0);
}

int	is_blank(char *line, int *valid)
{
	int i;

	i = 0;
	while (is_white_space(line[i]))
		i++;
	if (line[i] != '\0')
		return (0);
	*valid = 4;
	return (1);
}

int	comments(char *line, int *valid)
{
	int i;

	i = 0;
	while (is_white_space(line[i]))
		i++;
	if (line[i] != '#')
		return (0);
	*valid = 5;
	return (1);
}
