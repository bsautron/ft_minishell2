/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_priority_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:12:04 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/16 13:23:57 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <token.h>

t_token			*max_priority_token(t_token *tk_list)
{
	t_token		*max;

	max = NULL;
	while (tk_list)
	{
		if ((!max || token_to_priority(tk_list) > token_to_priority(max))
			&& token_to_priority(tk_list) > 0)
			max = tk_list;
		tk_list = tk_list->next;
	}
	return (max);
}
