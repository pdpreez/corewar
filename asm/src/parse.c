/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 07:39:20 by swilson           #+#    #+#             */
/*   Updated: 2018/09/28 11:19:48 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdlib.h>

void	save_loc_helper(t_asm_list *commands, t_asm_list *labels, int *size)
{
	while (commands)
	{
		while (labels && labels->line_no <= commands->line_no)
		{
			set_label_loc(labels->line_no, *size, labels);
			labels = labels->next;
		}
		set_command_loc(commands->line_no, *size, commands);
		*size += commands->size;
		commands = commands->next;
		if (!commands && labels)
		{
			while (labels)
			{
				set_label_loc(labels->line_no, *size, labels);
				labels = labels->next;
			}
		}
	}
}

void	save_locations(t_asm **asm_main)
{
	t_asm_list	*commands;
	t_asm_list	*labels;
	int			size;

	commands = (*asm_main)->n_commands;
	labels = (*asm_main)->n_labels;
	size = 0;
	save_loc_helper(commands, labels, &size);
	(*asm_main)->comm_size = size;
	(*asm_main)->program_size = size;
}

void	set_comments_and_count(t_asm **asm_main, int name, int comment)
{
	if (name != 1 || comment != 1)
	{
		if (comment != 1 && name == 1)
			ft_strcat((*asm_main)->header->comment, "too lazy to comment\n");
		else
			error_(0, "check your header information");
	}
	save_sizes(asm_main);
	save_locations(asm_main);
	save_final_list(asm_main);
}

int		parse_list(t_asm **asm_main)
{
	int			valid;
	t_asm_list	*temp;
	int			test;
	int			name;
	int			comment;

	temp = (*asm_main)->o_list;
	name = 0;
	comment = 0;
	while (temp)
	{
		if ((test = line_type(temp->data, &valid, asm_main)) == 0)
			error_(temp->line_no, "invalid input on line : ");
		else if (valid == 3)
			save_label(temp->data, asm_main, &valid, temp->line_no);
		else if (valid == 1)
			name++;
		else if (valid == 2)
			comment++;
		else if (valid < 0)
			save_commands(temp->data, asm_main, &valid, temp->line_no);
		temp = temp->next;
	}
	set_comments_and_count(asm_main, name, comment);
	return (1);
}

int		balancing_quotations(char *line)
{
	int	i;

	i = 0;
	if (line[0] != '"')
		return (0);
	while (line[++i])
	{
		if (line[i] == '"')
		{
			if (line[i - 1] == '\\')
				continue ;
			else
				break ;
		}
	}
	i++;
	while (line[i] && is_white_space(line[i]))
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}
