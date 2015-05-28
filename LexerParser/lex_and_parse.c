/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_and_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:55:48 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/22 21:39:58 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer_parser.h>

t_btree			*lex_and_parse(char *str, int *status)
{
	t_token		*tk_list;
	t_btree		*tree;

	tk_list = lex(str, status);
	tree = parse(tk_list, status);
	if (*status == STATUS_ERROR)
		return (NULL);
	return (tree);
}
