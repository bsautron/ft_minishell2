CC = gcc
NAME = ft_minishell2
CFLAGS = -Wextra -Wall -Werror
LIB = -L./libft -lft
LIBL = -L./libl -ll
LIBLD = -L./libld -lld
LIBCMD = -L./GetCmd -lgetcmd
LIBLEXPAR = -L./LexerParser -llexpar

OBJ_DIR = ../.obj/

SRC_MAIN = main.c \
		   ft_get_var_env.c \
		   ft_attrape_moi_si_tu_peux.c \
		   ft_signal_handler.c \
		   ft_pwd.c

SRC = $(SRC_MAIN)

INC_DIR = -I includes/ \
		  -I GetCmd/ \
		  -I LexerParser/ \
		  -I LexerParser/lexer/include/ \
		  -I LexerParser/parser/include/ \
		  -I LexerParser/token/include/

HEADER = includes/ft_sh.h \
		 includes/libft.h \
		 includes/libl.h \
		 includes/libld.h \
		 includes/get_next_line.h

OBJ = $(SRC:%.c=.obj/%.o)


.PHONY: all dor libs clean fclean re

all: dor libs $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LIB) $(LIBL) $(LIBLD) $(LIBCMD) $(LIBLEXPAR) -lncurses -g
	@echo "\033[32mReady!\033[0m"

dor:
	@mkdir $(OBJ_DIR) 2> /dev/null || env -i

libs:
	@make -C libft/
	@make -C libl/
	@make -C libld/
	@make -C GetCmd/
	@make -C LexerParser/

.obj/%.o: %.c $(HEADER)
	@echo "\033[33m 	$<"
	@$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $< -g

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIR) 2> /dev/null || env -i

fclean: clean
	@rm -f $(NAME)

re: fclean all
