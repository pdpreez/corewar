/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:04:41 by swilson           #+#    #+#             */
/*   Updated: 2018/09/27 14:05:30 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdlib.h>

int			correct_file(const char *file)
{
	int len;

	len = ft_strlen(file);
	if (file[len - 1] != 's' || file[len - 2] != '.' || len < 3)
		return (0);
	return (1);
}

t_asm_list	*read_from_file(char *file_name, t_asm **asm_main)
{
	int			fd;
	char		*line;
	int			i;
	t_asm_list	*list;
	t_asm_list	*temp;

	fd = open(file_name, O_RDONLY);
	i = 0;
	list = (*asm_main)->o_list;
	if (fd < 3)
	{
		ft_putstr("Error: There was an error opening the file\nReason: ");
		ft_putendl(strerror(errno));
		exit(0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		temp = new_node(line, ++i);
		add_node_front(&list, temp);
		free(line);
		line = NULL;
	}
	return (list);
}
