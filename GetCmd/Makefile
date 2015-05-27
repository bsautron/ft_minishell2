# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 05:41:35 by bsautron          #+#    #+#              #
#    Updated: 2015/05/27 21:14:14 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = getcmd.a
CFLAGS = -Wextra -Wall -Werror
LIB = -L../libft -lft
LIBL = -L../libl -ll
LIBLD = -L../libld -lld

OBJ_DIR = ../.obj/ \
		  ../.obj/getcmd/ \
		  ../.obj/getcmd/key/ \
		  ../.obj/getcmd/scope/

SRC_MAIN = ft_get_cmd.c \
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
		   ft_get_dirname.c \
		   ft_print_list_char.c \
		   ft_str_to_lstl.c \
		   ft_putstr_spec.c \
		   ft_lstl_to_str.c \
		   ft_set_term.c

SRC_KEY = ft_key_ctrl_d.c \
		  ft_key_ctrl_v.c \
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

SRC_SCOPE = ft_scope_free.c \
			ft_scope_len.c \
			ft_scope_new.c \
			ft_scope_print.c \
			ft_scope_push.c \
			ft_scope_pop.c \
			ft_scope_default.c \
			ft_scope_quote.c \
			ft_scope_bquote.c \
			ft_scope_cursh.c \
			ft_scope_dquote.c \
			ft_scope_subsh.c \
			ft_scope_hook.c

SRC = $(SRC_MAIN) \
	  $(addprefix key/, $(SRC_KEY)) \
	  $(addprefix scope/, $(SRC_SCOPE))

HEADER = includes/getcmd.h \
		 includes/ft_minishell.h \
		 includes/scope.h \
		 ../includes/libft.h \
		 ../includes/libl.h \
		 ../includes/libld.h \
		 ../includes/get_next_line.h

OBJ = $(SRC:%.c=%.o)


.PHONY: all dor libs clean fclean re

all: dor libs $(NAME)

$(NAME): $(OBJ) ../libft/libft.a
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[32mReady!\033[0m"

dor:
	@echo $(OBJ)
	@mkdir $(OBJ_DIR) 2> /dev/null || env -i

libs:
	@make -C ../libft/
	@make -C ../libl/
	@make -C ../libld/

../.obj/getcmd/%.o: %.c $(HEADER)
	@echo "\033[33m 	$<"
	@$(CC) $(CFLAGS) -I ../includes/ -o $@ -c $< -g

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIR) 2> /dev/null || env -i

fclean: clean
	@rm -f $(NAME)

re: fclean all
