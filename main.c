/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 16:58:42 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/10 10:24:03 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>
#include <stdio.h>

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
		tree = NULL;
		tree = lex_and_parse(cmd, &status);
		ft_exec_tree(tree, &lenv);
	//	print_tree(tree, POSTFIXE);

		//faire des free plz
		free(cmd);
	}
	(void)av;
	(void)ac;
	return (0);
}
