#include <ft_sh.h>
#include <stdio.h>

int		main(int ac, char **av, char **env)
{
	t_lstl	*lenv;
	char	*cmd;
	int		status;
	t_btree	*tree;

	lenv = NULL;
	lenv = ft_get_var_env(env);
	while (1)
	{
		cmd = ft_get_cmd(env);
		tree = lex_and_parse(cmd, &status);
		print_tree(tree, 2);
	}
	(void)av;
	(void)ac;
	return (0);
}
