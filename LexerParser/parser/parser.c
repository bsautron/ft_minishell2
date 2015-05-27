/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:03:33 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/16 13:25:04 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer_parser.h>


t_btree			*parse(t_token *tk_list)
{
	t_btree		*tree;
	t_token		*node;
	t_token		*left_tk_list;
	t_token		*right_tk_list;

	node = max_priority_token(tk_list);
	if (!node)
	{
		if (tk_list && tk_list->type == TK_SUBCOMMAND)
			tree = lex_and_parse(tk_list->value);
		else
			tree = new_btree(tk_list);
		return (tree);
	}
	else
		tree = new_btree(node);
	left_tk_list = head_token_list(node->prev);
	right_tk_list = node->next;
	if (node->prev)
		node->prev->next = NULL;
	if (node->next)
		node->next->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	tree->left = parse(left_tk_list);
	tree->right = parse(right_tk_list);
	return (tree);
}
