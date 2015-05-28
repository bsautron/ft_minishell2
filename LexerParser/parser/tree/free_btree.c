/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_btree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:49:32 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/22 19:52:41 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree.h>

void		free_btree(t_btree *tree)
{
	if (!tree)
		return ;
	free_token_list(tree->tk);
	free_btree(tree->left);
	free_btree(tree->right);
	free(tree);
}
