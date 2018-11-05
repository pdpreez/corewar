/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <swilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:20:07 by swilson           #+#    #+#             */
/*   Updated: 2018/09/28 11:32:22 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libft/get_next_line.h"
# include "op.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# define LINE_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789 ,%:-"

typedef struct			s_asm_list
{
	char				*data;
	char				*hex;
	int					location;
	int					size;
	int					line_no;
	struct s_asm_list	*next;
}						t_asm_list;

typedef struct			s_asm
{
	int					comm_size;
	int					program_size;
	t_header			*header;
	t_asm_list			*o_list;
	t_asm_list			*n_commands;
	t_asm_list			*n_labels;
	t_asm_list			*final_list;
}						t_asm;

void					exit_str(char *str);
int						error_(int line_no, char *output);
int						correct_file(const char *file);
t_asm_list				*read_from_file(char *file_name, t_asm **asm_main);
void					initialize(t_asm **asm_main, char *name);
char					**init_commands(void);
t_asm_list				*new_node(char *line, int pos);
void					add_node_front(t_asm_list **head, t_asm_list *node);
int						is_name(char *line, int *valid, t_asm **asm_main);
int						is_label(char *line, int *valid);
int						is_comment(char *line, int *valid, t_asm **main);
int						is_command(char *line, int *valid);
int						parse_list(t_asm **asm_main);
int						line_type(char *line, int *valid, t_asm **asm_main);
int						balancing_quotations(char *line);
void					print_list(t_asm_list *list);
void					save_commands(char *str, t_asm **main, int *v, int loc);
void					save_label(char *str, t_asm **asm_main, int *v, int n);
int						len_to_char(char *s, int c);
int						is_white_space(char c);
int						is_blank(char *line, int *valid);
int						comments(char *line, int *valid);
int						is_valid_nbr(char *s, int sign);
int						check_register(char *str);
int						check_indirect(char *str);
char					*copy_till_space(char *str);
int						is_valid_label(char *str, t_asm_list *labels);
int						check_direct(char *str, t_asm_list *labels);
int						check_r_d_i(char *str, t_asm_list *labels);
int						check_r_d(char *str, t_asm_list *labels);
int						check_r_i(char *str);
int						check_d_i(char *str, t_asm_list *labels);
void					print_name_comment(t_asm **asm_main, char *name);
t_asm_list				*new_final_node(char *line, t_asm_list *command);
int						go_to_param(char *str, int label_size);
void					print_help(void);
int						check_empty_end(char *str);
int						save_header_comment(char *line, t_asm **asm_main);
int						save_header_name(char *line, t_asm **asm_main);
char					*set_final_line(t_asm_list *node, t_asm_list *labels);
void					save_final_list(t_asm **asm_main);
void					set_label_loc(int line_n, int pos, t_asm_list *labels);
void					set_command_loc(int line_n, int pos, t_asm_list *comd);
void					save_sizes(t_asm **asm_main);
/*
** Functions
*/

int						cw_null(char *str, int loc, t_asm_list *labels);
int						cw_live(char *str, int loc, t_asm_list *labels);
int						cw_ld(char *str, int loc, t_asm_list *labels);
int						cw_st(char *str, int loc, t_asm_list *labels);
int						cw_add(char *str, int loc, t_asm_list *labels);
int						cw_sub(char *str, int loc, t_asm_list *labels);
int						cw_and(char *str, int loc, t_asm_list *labels);
int						cw_or(char *str, int loc, t_asm_list *labels);
int						cw_xor(char *str, int loc, t_asm_list *labels);
int						cw_zjmp(char *str, int loc, t_asm_list *labels);
int						cw_ldi(char *str, int loc, t_asm_list *labels);
int						cw_sti(char *str, int loc, t_asm_list *labels);
int						cw_fork(char *str, int loc, t_asm_list *labels);
int						cw_lld(char *str, int loc, t_asm_list *labels);
int						cw_lldi(char *str, int loc, t_asm_list *labels);
int						cw_lfork(char *str, int loc, t_asm_list *labels);
int						cw_aff(char *str, int loc, t_asm_list *labels);
void					adjust_ret(int *ret, int *i, int hold, char *str);

static int (*g_func_ptr[17])(char *str, int loc, t_asm_list *labels) =
{
	cw_null, cw_ld, cw_st, cw_add, cw_sub, cw_and, cw_or,
	cw_xor, cw_zjmp, cw_ldi, cw_sti, cw_fork, cw_lld, cw_lldi,
	cw_lfork, cw_aff, cw_live
};

/*
**	converter functions
*/
long long				long_atoi(const char *str);
long long				clean_value(long long n);
char					*hex(long long n, int bits);
int						get_byte_no(char c);
int						i_byte_no(char c);

void					live(char *str, int fd);
void					ld(char *str, int fd);
void					st(char *str, int fd);
void					add(char *str, int fd);
void					sub(char *str, int fd);
void					and(char *str, int fd);
void					or(char *str, int fd);
void					xor(char *str, int fd);
void					zjmp(char *str, int fd);
void					ldi(char *str, int fd);
void					sti(char *str, int fd);
void					ft_fork(char *str, int fd);
void					lld(char *str, int fd);
void					lldi(char *str, int fd);
void					ft_lfork(char *str, int fd);
void					aff(char *str, int fd);
int						check_encoding_byte(char *str, int i, int j);
int						check_sti(char *str, int i, int j);
void					convert_header(t_header *header, int fd);
void					convert_code(t_asm *list, int fd);
void					store_core_int_4(int number, int fd);
void					store_core_int_2(int number, int fd);

#endif
