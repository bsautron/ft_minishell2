#include <ft_sh.h>

int		ft_exec_tree(t_btree *tree, t_lstl *lenv)
{
	char		**env;
	int			ret;

	if (tree)
	{
		ret = ft_exec_tree(tree->left, lenv);
		if (tree->tk->type == 1)
		{
			env = ft_lstl_to_tab(lenv);
			return (ft_interpret(tree->tk, env));
		}
		if ((ret != 0 && tree->tk->type == TK_OR_OPERATOR)
			|| (ret == 0 && tree->tk->type == TK_AND_OPERATOR))
			return (ft_exec_tree(tree->right, lenv));
		else
			return (ret);
	}
	return (0);
}
