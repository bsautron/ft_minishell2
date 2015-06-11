#include <ft_sh.h>
#include <stdio.h>

// Pas de split_white_space dans le setenv plz
int		main(int ac, char **av, char **env)
{
	t_lstl	*lenv;
	char	*cmd;
	t_btree	*tree;
	int		status;

	lenv = NULL;
	lenv = ft_get_var_env(env);
	while (1)
	{
		cmd = ft_get_cmd(env);
		write(1, "\n", 1);
		tree = lex_and_parse(cmd, &status);
		ft_exec_tree(tree, lenv);
		//print_tree(tree, 3);
		//faire des free plz
	}
	(void)av;
	(void)ac;
	return (0);
}
