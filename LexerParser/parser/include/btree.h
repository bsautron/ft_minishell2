/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:28:19 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/22 19:52:09 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include <libft.h>
# include <token.h>
# include <stdio.h>/////

# define T_LEFT		0
# define T_RIGHT	1

# define INFIXE		1
# define SUFIXE		2
# define POSTFIXE	3

typedef struct			s_btree
{
	t_token				*tk;
	struct s_btree		*left;
	struct s_btree		*right;
}						t_btree;

t_btree					*new_btree(t_token *tk);
void					print_tree(t_btree *tree, int mode);
int						btree_is_leaf(t_btree *tree);
void					free_btree(t_btree *tree);

#endif
