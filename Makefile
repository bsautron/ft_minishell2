# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/09 22:38:06 by bsautron          #+#    #+#              #
#    Updated: 2015/07/08 05:56:05 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_minishell2
#CFLAGS = -Wextra -Wall -Werror

LIB = -L./libft -lft
LIBL = -L./libl -ll
LIBLD = -L./libld -lld
LIBCMD = -L./GetCmd -lgetcmd
LIBLEXPAR = -L./LexerParser -llexpar

OBJ_DIR = .obj/ \
		  .obj/Bultins/ \
		  .obj/Interpret

SRC_MAIN = main.c \
		   ft_get_var_env.c \
		   ft_attrape_moi_si_tu_peux.c \
		   ft_signal_handler.c \
		   ft_interpret.c \
		   ft_get_env.c \
		   ft_tk_to_tab.c \
		   ft_lstl_to_tab.c \
		   ft_exec_tree.c

SRC_BULTINS = ft_pwd.c \
			  ft_setenv.c

SRC_INTERPRET = ft_cmd_create.c \
				ft_cmd_add.c \
				ft_cmd_add_back.c

SRC = $(SRC_MAIN) \
	  $(addprefix Bultins/, $(SRC_BULTINS)) \
	  $(addprefix Interpret/, $(SRC_INTERPRET))

INC_DIR = -I includes/ \
		  -I libft/includes \
		  -I libl/includes \
		  -I libld/includes \
		  -I GetCmd/ \
		  -I LexerParser/ \
		  -I LexerParser/lexer/include/ \
		  -I LexerParser/parser/include/ \
		  -I LexerParser/token/include/ \
		  -I Interpret/includes/

HEADER = includes/ft_sh.h \
		 libft/includes/libft.h \
		 libft/includes/get_next_line.h \
		 libl/includes/libl.h \
		 libld/includes/libld.h \
		 Interpret/includes/interpret.h

OBJ = $(SRC:%.c=.obj/%.o)

LIBS = ./GetCmd/libgetcmd.a \
	   ./LexerParser/liblexpar.a \
	   ./libft/libft.a \
	   ./libl/libl.a \
	   ./libld/libld.a

.PHONY: all dor libs clean fclean re

all: dor libs $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LIB) $(LIBL) $(LIBLD) $(LIBCMD) $(LIBLEXPAR) -lncurses -g
	@echo "\033[32mReady! but no Flags\033[0m"

dor:
	@mkdir $(OBJ_DIR) 2> /dev/null || env -i

libs:
	@make -C libft/
	@make -C libl/
	@make -C libld/
	@make -C GetCmd/
	@make -C LexerParser/

.obj/%.o: %.c $(HEADER) $(LIBS)
	@echo "\033[33m 	$<"
	@$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $< -g

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIR) 2> /dev/null || env -i

fclean: clean
	@rm -f $(NAME)

re: fclean all
