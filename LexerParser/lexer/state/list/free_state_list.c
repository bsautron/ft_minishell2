/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_state_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 14:22:27 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/19 14:32:59 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void		free_state_list(t_state *state_list)
{
	t_state	*tmp;

	while (state_list)
	{
		tmp = state_list->next;
		free(state_list);
		state_list = tmp;
	}
}
