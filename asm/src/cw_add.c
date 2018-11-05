/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/27 13:39:30 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	adjust_index(int *i, char *str)
{
	int j;

	*i = (*(str + *i + 2) == ',') ? *i + 3 : *i + 4;
	j = *i;
	*i = (str[j] == ' ') ? ++j : j;
}

int		cw_add(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;
	int j;

	i = go_to_param(str, 3);
	ret = 2;
	(void)labels;
	if (check_register(str + i))
	{
		ret += 1;
		adjust_index(&i, str);
		if (check_register(str + i))
		{
			ret += 1;
			i = (*(str + i + 2) == ',') ? i + 3 : i + 4;
			j = i;
			i = (str[j] == ' ') ? ++j : j;
			if (check_register(str + i))
				if (check_empty_end(str + i))
					return (ret + 1);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}
