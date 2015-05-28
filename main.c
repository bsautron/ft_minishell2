#include <ft_sh.h>
#include <stdio.h>

int		main(int ac, char **av, char **env)
{
	char	*cmd;
	int		status;
	t_btree	*tree;

	while (1)
	{
		cmd = ft_get_cmd(env);
		tree = lex_and_parse(cmd, &status);
		print_tree(tree, 3);
		dprintf(1, "%s\n", "");
	}

	(void)av;
	(void)ac;
	return (0);
}
