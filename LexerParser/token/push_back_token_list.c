/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_token_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:23:44 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/16 12:54:27 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <token.h>

void			push_back_token_list(t_token *token, t_token **tk_list)
{
	t_token		*tmp;

	tmp = *tk_list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		tmp->next = token;
		token->prev = tmp;
	}
	else
		*tk_list = token;
}
