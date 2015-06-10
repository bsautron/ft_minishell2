#include <ft_sh.h>

int		ft_exec_tree(t_btree *tree, t_lstl *lenv)
{
	char		**env;
	char		**cmd;

	if (tree)
	{
		// checker type operator
		// puis ft_exec() que si cest une feuille
		cmd = ft_tk_to_tab(tree->tk);
		env = ft_lstl_to_tab(lenv);
		ft_exec(ft_strjoin("/bin/", cmd[0]), cmd, env);  
		ft_exec_tree(tree->left, lenv);
		ft_exec_tree(tree->right, lenv);
	}
	return (0);
}
