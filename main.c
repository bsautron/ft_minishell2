#include <ft_sh.h>
#include <stdio.h>

int		main(int ac, char **av, char **env)
{
	t_lstl	*lenv;
	char	*cmd;
	t_btree	*tree;
	int		status;
	char	**tab;

	lenv = NULL;
	lenv = ft_get_var_env(env);
	while (1)
	{
		cmd = ft_get_cmd(env);
		tree = lex_and_parse(cmd, &status);
		tab = ft_tk_to_tab(tree->tk);
		print_tree(tree, 2);
		//ft_exec(ft_strjoin("/bin/", tab[0]), tab, ft_lstl_to_tab(lenv));
		//faire des free plz
	}
	(void)av;
	(void)ac;
	return (0);
}
