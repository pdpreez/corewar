/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:50:31 by swilson           #+#    #+#             */
/*   Updated: 2018/09/27 16:41:12 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdlib.h>

void	print_list(t_asm_list *list)
{
	t_asm_list *temp;

	temp = list;
	while (temp)
	{
		ft_putstr(temp->data);
		ft_putstr("\t| ");
		ft_putnbr(temp->line_no);
		ft_putstr("\t| ");
		ft_putnbr(temp->location);
		ft_putstr("\t| ");
		ft_putnbr(temp->size);
		ft_putstr("\n");
		temp = temp->next;
	}
}

void	print_name_comment(t_asm **asm_main, char *name)
{
	ft_putstr("Assembling ");
	ft_putstr(name);
	ft_putendl(":");
	ft_putstr("\t\t");
	ft_putendl((*asm_main)->header->prog_name);
	ft_putstr("\t\t");
	ft_putendl((*asm_main)->header->comment);
}

void	print_help(void)
{
	ft_putstr("Usage help : pass the '.s' file as an argument\n");
	ft_putstr("\te.g ./asm example.s\n\n");
	ft_putstr("Valid instructions : only tabs and spaces are allowed before\n");
	ft_putstr("\tand after the instruction name\n");
	ft_putstr("\tuse a comma ',' or space ' '\n\tor both ', ");
	ft_putstr("' to separate the instruction arguments\n");
	exit(0);
}
