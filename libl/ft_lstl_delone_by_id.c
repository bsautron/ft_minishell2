/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lslt_delone_by_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:53:37 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/24 20:15:53 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libl.h"

void	ft_lstl_delone_by_id(t_lstl **begin, size_t id)
{
	size_t	i;
	t_lstl	*tmp;
	t_lstl	*free_me;

	tmp = *begin;
	if (*begin)
	{
		if (id == 0)
		{
			*begin = tmp->next;
			free(tmp->str);
			free(tmp);
		}
		else
		{
			i = 1;
			while (i++ < id && tmp)
				tmp = tmp->next;
			free_me = tmp->next;
			tmp->next = tmp->next->next;
			free(free_me->str);
			free(free_me);
		}
	}
}
