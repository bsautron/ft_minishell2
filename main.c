#include <ft_sh.h>
#include <stdio.h>

int		main(int ac, char **av, char **env)
{
	char	*cmd;
	int		status;
	t_btree	*tree;

	dprintf(1, "%s\n", "begin");
	cmd = ft_get_cmd(env);
	dprintf(1, "cmd = %s\n%s\n", cmd, "--------------------\n");
	tree = lex_and_parse(cmd, &status);
	print_tree(tree, 3);

	(void)env;
	(void)av;
	(void)ac;
	return (0);
}
