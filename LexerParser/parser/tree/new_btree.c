/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_btree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:16:33 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/16 12:17:07 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree.h>

t_btree			*new_btree(t_token *tk)
{
	t_btree		*new;

	new = (t_btree*)malloc(sizeof(t_btree));
	new->tk = tk;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
