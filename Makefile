# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 05:41:35 by bsautron          #+#    #+#              #
#    Updated: 2015/04/03 03:43:46 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_minishell2
SRC = main.c \
	  ft_prompt.c \
	  ft_outc.c \
	  ft_make_instruction.c \
	  ft_onlyesp.c \
	  ft_reset_term.c \
	  ft_setenv.c \
	  ft_pwd.c \
	  ft_replace.c \
	  ft_get_env.c \
	  ft_parser.c \
	  ft_signal_handler.c \
	  ft_move_cursor.c \
	  ft_lstl_get_link_by_id.c \
	  ft_lstld_get_link_by_id.c \
	  ft_refresh.c \
	  ft_print_list_char.c \
	  ft_str_to_lstl.c \
	  ft_putstr_spec.c \
	  ft_lstl_to_str.c \
	  ft_set_term.c \
	  \
	  ft_key_ctrl_d.c \
	  ft_key_back_space.c \
	  ft_key_delete.c \
	  ft_key_down.c \
	  ft_key_end.c \
	  ft_key_home.c \
	  ft_key_left.c \
	  ft_key_printable.c \
	  ft_key_right.c \
	  ft_key_up.c \
	  ft_key_alt_right.c \
	  ft_key_alt_left.c \
	  ft_key_alt_up.c \
	  ft_key_alt_down.c
DIR_H = ./includes
HEADER = $(DIR_H)/ft_minishell.h \
		 $(DIR_H)/libft.h \
		 $(DIR_H)/libl.h \
		 $(DIR_H)/libld.h \
		 $(DIR_H)/get_next_line.h
OBJ = $(SRC:%.c=.obj/%.o)
CFLAGS = -Wextra -Wall -Werror
LIB = -L./libft -lft
LIBL = -L./libl -ll
LIBLD = -L./libld -lld

.PHONY: all libs clean fclean re

all: dor libs $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LIB) $(LIBL) $(LIBLD) -lncurses -g
	@echo "\033[32mReady!\033[0m"

dor:
	@mkdir .obj 2> /dev/null || env -i

libs:
	@make -C libft/
	@make -C libl/
	@make -C libld/

.obj/%.o: %.c $(HEADER)
	@echo "\033[33m 	$<"
	@$(CC) -o $@ -I includes/ -c $< -g

clean:
	rm -f $(OBJ)
	@rmdir .obj 2> /dev/null || env -i

fclean: clean
	rm -f $(NAME)

re: fclean all
