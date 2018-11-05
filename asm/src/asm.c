/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:13:18 by swilson           #+#    #+#             */
/*   Updated: 2018/11/05 13:24:27 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdlib.h>

char	*get_file_name(char *str)
{
	char	*name;
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i > 0 && str[i] != '.')
		i--;
	tmp = ft_strsub(str, 0, i + 1);
	name = ft_strjoinfree(tmp, "cor");
	return (name);
}

void	writing_to_file(t_asm *asm_main, char *argv)
{
	char	*name;
	int		n;
	int		fd;

	name = get_file_name(argv);
	fd = open(name, O_RDWR | O_CLOEXEC | O_CREAT, S_IRWXU);
	convert_header(asm_main->header, fd);
	n = 0;
	convert_code(asm_main, fd);
	close(fd);
	free(name);
}

int		main(int argc, char *argv[])
{
	t_asm	*asm_main;

	if (argc == 2)
	{
		if (ft_strequ(argv[1], "-help"))
			print_help();
		initialize(&asm_main, argv[1]);
		asm_main->o_list = read_from_file(argv[1], &asm_main);
		parse_list(&asm_main);
		asm_main->header->prog_size = asm_main->program_size;
		print_name_comment(&asm_main, argv[1]);
		writing_to_file(asm_main, argv[1]);
	}
	else
		error_(0, "usage: need to pass a '.s' file as an argument, \n\
		run './asm -help' for help\n");
	exit(0);
	return (0);
}
