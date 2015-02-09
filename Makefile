CC = gcc
SRC = main.c \
	  ft_prompt.c \
	  ft_stop.c \
	  ft_getpath.c \
	  ft_getabsolute_path.c \
	  ft_cmd.c \
	  ft_cd.c \
	  ft_onlyesp.c \
	  ft_pwd.c \
	  ft_first_redir.c \
	  ft_isbultin.c \
	  ft_get_id_var.c \
	  ft_setenv.c \
	  ft_unsetenv.c \
	  ft_cmd_is_in_path.c \
	  ft_getcmd.c \
	  ft_strsplit_white_space.c \
	  ft_strsplit2.c \
	  ft_strsplit3.c \
	  ft_exec.c \
	  ft_strtrim_new.c \
	  ft_getdir.c \
	  ft_getpath_pwd.c \
	  ft_nb_env.c \
	  ft_nbargv.c \
	  ft_get_prev_dir.c \
	  ft_error_cd.c \
	  ft_not_dir.c \
	  ft_what.c \
	  ft_get_dirname.c \
	  ft_nclear.c \
	  ft_make_history.c \
	  ft_join_or_del.c \
	  ft_runpipe.c \
	  ft_runsup.c \
	  ft_runinf.c \
	  ft_rundoublesup.c \
	  ft_env.c
OBJ = $(SRC:.c=.o)
NAME = ft_minishell2
FLAGS = -Wall -Wextra -Werror -g3
LIB = -L./libft -lft

all: $(NAME)

$(NAME):
	@make -C libft/
	@$(CC) $(FLAGS) -I libft/includes/ -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LIB) -g -lncurses 
	@echo "Dat Shell -> Made"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
