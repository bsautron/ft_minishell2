#include <ft_sh.h>

int		ft_exec_tree(t_btree *tree, t_lstl *lenv)
{
	char		**env;
	char		**cmd;
	int			ret;

	if (tree)
	{
		ret = ft_exec_tree(tree->left, lenv);
		if (tree->tk->type == 1)
		{
			cmd = ft_tk_to_tab(tree->tk);
			env = ft_lstl_to_tab(lenv);
			return (ft_exec(ft_strjoin("/bin/", cmd[0]), cmd, env));
		}
		if ((ret != 0 && tree->tk->type == TK_OR_OPERATOR)
			|| (ret == 0 && tree->tk->type == TK_AND_OPERATOR))
			return (ft_exec_tree(tree->right, lenv));
		else
			return (ret);
	}
	return (0);
}
