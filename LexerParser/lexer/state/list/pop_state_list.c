/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_state_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 23:14:57 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/11 23:44:29 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void			pop_state_list(t_state **state_list)
{
	t_state		*tmp;

	if (*state_list)
	{
		tmp = *state_list;
		*state_list = (*state_list)->next;
		free(tmp);
	}
}
