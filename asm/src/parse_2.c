/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 07:52:21 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/28 08:47:30 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdlib.h>

t_asm_list	*sanitised_command(int loc, t_asm_list *list)
{
	t_asm_list *commands;

	commands = list;
	while (commands)
	{
		if (commands->line_no == loc)
			return (commands);
		commands = commands->next;
	}
	return (NULL);
}

void		save_sizes(t_asm **asm_main)
{
	t_asm_list	*temp;
	t_asm_list	*command;
	t_asm_list	*labels;
	int			size;
	int			valid;

	temp = (*asm_main)->n_commands;
	labels = (*asm_main)->n_labels;
	while (temp)
	{
		line_type(temp->data, &valid, asm_main);
		if (valid < 0)
		{
			command = sanitised_command(temp->line_no, (*asm_main)->n_commands);
			if (command != NULL)
			{
				size = (*(g_func_ptr[(valid * -1)]))(command->data,
						command->line_no, (*asm_main)->n_labels);
				if (size)
					command->size = size;
			}
		}
		temp = temp->next;
	}
}

void		set_label_loc(int line_num, int pos, t_asm_list *labels)
{
	t_asm_list *temp;

	temp = labels;
	while (temp)
	{
		if (temp->line_no == line_num)
			temp->location = pos;
		temp = temp->next;
	}
}

void		set_command_loc(int line_num, int pos, t_asm_list *commands)
{
	t_asm_list *temp;

	temp = commands;
	while (temp)
	{
		if (temp->line_no == line_num)
			temp->location = pos;
		temp = temp->next;
	}
}
