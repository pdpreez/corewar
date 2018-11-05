/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:30:32 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/27 09:45:07 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	cw_st(char *str, int loc, t_asm_list *labels)
{
	int i;
	int ret;
	int hold;

	i = go_to_param(str, 2);
	ret = 2;
	(void)labels;
	if (check_register(str + i))
	{
		ret += 1;
		i += len_to_char(str + i, ',');
		i = (str[i + 1] == ' ') ? i + 2 : i + 1;
		if ((hold = check_r_i(str + i)) > 0)
			if (check_empty_end(str + i))
				return (ret + hold);
	}
	error_(loc, "check the format on line : ");
	return (0);
}
