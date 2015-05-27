/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:29:15 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/16 12:59:34 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int		main(int ac, char **av)
{
	t_btree *tree;
	if (ac > 1)
	{
		tree = lex_and_parse(av[1]);
		dprintf(1, "%s\n", "---print de l'arbre---");
		print_tree(tree, POSTFIXE);
	}
	
	(void)ac;
	(void)av;
	(void)tree;
	return (0);
}
