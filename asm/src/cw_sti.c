/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/28 11:38:50 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	go_to_param(char *str, int label_size)
{
	int i;

	i = 0;
	while (is_white_space(str[i]))
		i++;
	i += label_size;
	while (is_white_space(str[i]))
		i++;
	return (i);
}

int	set_ret(int hold)
{
	if (hold == 1)
		return (1);
	return (2);
}

int	cw_sti(char *str, int loc, t_asm_list *labels)
{
	int i;
	int j;
	int ret;
	int hold;

	ret = 3;
	i = go_to_param(str, 3);
	if (check_register(str + i))
	{
		j = len_to_char(str, ',');
		i = (str[j + 1] == ' ') ? j + 2 : j + 1;
		if ((hold = check_r_d_i(str + i, labels)) > 0)
		{
			j = len_to_char(str + i, ' ');
			if (j == -1)
				j = len_to_char(str + i, ',');
			i += j + 1;
			ret += set_ret(hold);
			if ((hold = check_r_d(str + i, labels)) > 0)
				if (check_empty_end(str + i))
					return (ret + hold);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}
