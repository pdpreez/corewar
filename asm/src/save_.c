/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fledwaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 07:54:18 by fledwaba          #+#    #+#             */
/*   Updated: 2018/09/28 09:10:59 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdlib.h>

int		save_header_name(char *line, t_asm **asm_main)
{
	int i;

	i = 0;
	if ((ft_strlen(line) - 1) > PROG_NAME_LENGTH)
		error_(0, "name too long");
	while ((line[i] != '"') && line[i])
	{
		(*asm_main)->header->prog_name[i] = line[i];
		i++;
	}
	return (1);
}

int		save_header_comment(char *line, t_asm **asm_main)
{
	int i;

	i = 0;
	if ((ft_strlen(line) - 1) > COMMENT_LENGTH)
		error_(0, "comment too long");
	while ((line[i] != '"') && line[i])
	{
		(*asm_main)->header->comment[i] = line[i];
		i++;
	}
	return (1);
}

int		is_white_space_rev(char *s, int start)
{
	int i;

	i = 0;
	while (((s[start - i] == ' ') || (s[start - i] == '\t'))
			&& (s[start] != '\0'))
	{
		i++;
		if (start - i < 0)
			break ;
	}
	return (i);
}

void	save_commands(char *str, t_asm **asm_main, int *valid, int loc)
{
	t_asm_list	*temp;
	char		*line;
	int			i;
	int			loc_hash;
	int			end;

	i = 0;
	loc_hash = len_to_char(str, '#');
	if (loc_hash == -1)
		loc_hash = len_to_char(str, ';');
	if (loc_hash == -1)
		loc_hash = len_to_char(str, '\0');
	end = is_white_space_rev(str, loc_hash - 1);
	(*valid)++;
	while (is_white_space(str[i]))
		i++;
	loc_hash -= i;
	line = ft_strsub(str, i, loc_hash - end);
	temp = new_node(line, loc);
	free(line);
	add_node_front(&((*asm_main)->n_commands), temp);
}

void	save_label(char *str, t_asm **asm_main, int *valid, int loc)
{
	t_asm_list	*temp;
	char		*line;
	int			loc_colon;
	int			j;

	loc_colon = len_to_char(str, LABEL_CHAR);
	j = 0;
	while (is_white_space(str[j]))
		j++;
	line = ft_strsub(str, j, (j > 0) ? loc_colon - 1 : loc_colon);
	loc_colon++;
	while (is_white_space(str[loc_colon]))
		loc_colon++;
	line_type(str + loc_colon, valid, asm_main);
	if (*valid < 0)
		save_commands(str + loc_colon, asm_main, valid, loc);
	temp = new_node(line, loc);
	free(line);
	add_node_front(&((*asm_main)->n_labels), temp);
}
