/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:27:10 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/16 13:18:26 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree.h>
#include <libft.h>

static void		print_token_list(t_token *tk_list)
{
	while (tk_list)
	{
		dprintf(1, "tk %d/ %s\n", tk_list->type, tk_list->value);
		tk_list = tk_list->next;
	}
}

static void		infixe(t_btree *tree)
{
	if (tree)
	{
		infixe(tree->left);
		infixe(tree->right);
		print_token_list(tree->tk);
		dprintf(1, "%s\n", "---");
	}
}

static void		sufixe(t_btree *tree)
{
	if (tree)
	{
		sufixe(tree->left);
		print_token_list(tree->tk);
		dprintf(1, "%s\n", "---");
		sufixe(tree->right);
	}
}

static void		postfixe(t_btree *tree, char *pos)
{
	if (tree)
	{
		printf("%s\n", pos);
		print_token_list(tree->tk);
		dprintf(1, "%s\n", "---");
		postfixe(tree->left, "left");
		postfixe(tree->right, "right");
	}
}

void	print_tree(t_btree *tree, int mode)
{
	if (mode == 1)
		infixe(tree);
	else if (mode == 2)
		sufixe(tree);
	else if (mode == 3)
		postfixe(tree, "middle");
}
