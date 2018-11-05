/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/28 11:07:13 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	cw_ldi(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;
	int hold;

	i = go_to_param(str, 3);
	ret = 2;
	if ((hold = check_r_d_i(str + i, labels)) > 0)
	{
		adjust_ret(&ret, &i, hold, str);
		if ((hold = check_r_d(str + i, labels)) > 0)
		{
			ret += hold;
			i += len_to_char(str + i, ',');
			i = (str[i + 1] == ' ') ? i + 2 : i + 1;
			if (check_register(str + i))
				if (check_empty_end(str + i))
					return (ret + 1);
		}
	}
	error_(loc, "check the format on line : ");
	return (0);
}
