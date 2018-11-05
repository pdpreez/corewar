# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/28 11:34:43 by rhohls            #+#    #+#              #
#    Updated: 2018/09/28 11:34:47 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= compile
VM			= corewar
ASM			= asm
VM_PATH		= vm
ASM_PATH	= asm_dir

all:	$(NAME)

$(NAME):
	@make -C $(VM_PATH)
	@make -C $(ASM_PATH)
	@cp ./$(VM_PATH)/corewar ./
	@cp ./$(ASM_PATH)/asm ./

cleanfile:
	@rm -f $(VM)
	@rm -f $(ASM)

clean: cleanfile
	@make -C $(VM_PATH) clean
	@make -C $(ASM_PATH) clean

fclean: cleanfile
	@make -C $(VM_PATH) fclean 
	@make -C $(ASM_PATH) fclean

re:	fclean all

.PHONY:		all clean fclean re
