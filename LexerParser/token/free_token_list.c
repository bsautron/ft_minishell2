/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:21:23 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/22 19:50:39 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <token.h>

void			free_token_list(t_token *tk_list)
{
	t_token		*tmp;
	
	while (tk_list)
	{
		tmp = tk_list->next;
		free(tk_list->value);
		free(tk_list);
		tk_list = tmp;
	}
}
