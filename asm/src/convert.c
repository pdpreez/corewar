/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:00:09 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/27 13:45:35 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void				convert_sub(char *data, int fd)
{
	if (ft_strstr(data, "sti"))
		sti(data, fd);
	else if (ft_strstr(data, "st"))
		st(data, fd);
	else if (ft_strstr(data, "add"))
		add(data, fd);
	else if (ft_strstr(data, "sub"))
		sub(data, fd);
	else if (ft_strstr(data, "and"))
		and(data, fd);
	else if (ft_strstr(data, "lfork"))
		ft_lfork(data, fd);
	else if (ft_strstr(data, "fork"))
		ft_fork(data, fd);
	else if (ft_strstr(data, "xor"))
		xor(data, fd);
	else if (ft_strstr(data, "or"))
		or(data, fd);
	else if (ft_strstr(data, "zjmp"))
		zjmp(data, fd);
}

void				convert_code(t_asm *list, int fd)
{
	t_asm_list		*tmp;

	tmp = list->final_list;
	while (tmp)
	{
		if (ft_strstr(tmp->data, "live"))
			live(tmp->data, fd);
		else if (ft_strstr(tmp->data, "aff"))
			aff(tmp->data, fd);
		else if (ft_strstr(tmp->data, "lldi"))
			lldi(tmp->data, fd);
		else if (ft_strstr(tmp->data, "ldi"))
			ldi(tmp->data, fd);
		else if (ft_strstr(tmp->data, "lld"))
			lld(tmp->data, fd);
		else if (ft_strstr(tmp->data, "ld"))
			ld(tmp->data, fd);
		else
			convert_sub(tmp->data, fd);
		tmp = tmp->next;
	}
}
