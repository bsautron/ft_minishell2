/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:29:15 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/19 14:01:40 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int		main(int ac, char **av)
{
	t_btree *tree;
	int		status;

	if (ac > 1)
	{
		tree = lex_and_parse(av[1], &status);
		if (status == STATUS_OK){
		dprintf(1, "%s\n", "---print de l'arbre---");
		print_tree(tree, POSTFIXE);}
		else if (status == STATUS_ERROR)
			printf("Lol\n");
	}
	
	(void)ac;
	(void)av;
	(void)tree;
	return (0);
}
