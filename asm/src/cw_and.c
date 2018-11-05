/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/28 11:37:31 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_empty_end(char *str)
{
	int i;

	i = 0;
	while (ft_strchr(LINE_CHARS, str[i]) && (str[i] != ' ') && str[i])
		i++;
	if (str[i])
		return (0);
	return (1);
}

void	adjust_ret(int *ret, int *i, int hold, char *str)
{
	int j;

	j = len_to_char(str + *i, ' ');
	if (j == -1)
		j = len_to_char(str + *i, ',');
	(*i) += j;
	(*i)++;
	if (hold == 1)
		*ret += 1;
	else if ((hold == 2) || (hold == 3))
		*ret += 2;
}

int		cw_and(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;
	int hold;

	i = go_to_param(str, 3);
	ret = 2;
	(void)labels;
	if ((hold = check_r_d_i(str + i, labels)) > 0)
	{
		adjust_ret(&ret, &i, hold, str);
		if (hold == 2)
			ret += 2;
		if ((hold = check_r_d_i(str + i, labels)) > 0)
		{
			adjust_ret(&ret, &i, hold, str);
			if (hold == 2)
				ret += 2;
			if (check_register(str + i))
				if (check_empty_end(str + i))
					return (ret + 1);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}
