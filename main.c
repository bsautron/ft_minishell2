#include <ft_sh.h>
#include <stdio.h>

int		main(int ac, char **av, char **env)
{
	char	*cmd;
	t_btree	*tree;

	dprintf(1, "%s\n", "begin");
	cmd = ft_get_cmd(env);
	tree = lex_and_parse(cmd);
	print_tree(tree, 3);

	(void)env;
	(void)av;
	(void)ac;
	return (0);
}
