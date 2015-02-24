/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:03:30 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/24 19:26:36 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libl.h"

void	ft_lstl_insert(t_lstl **begin, char *str, size_t pos)
{
	t_lstl	*new;
	t_lstl	*tmp;
	t_lstl	*save_next;
	size_t	i;

	new = ft_lstl_create(str);
	tmp = *begin;
	if (!(*begin))
		*begin = new;
	else if (pos == 0)
	{
		new->next = tmp;
		*begin = new;
	}
	else
	{
		i = 1;
		while (tmp && i++ < pos)
			tmp = tmp->next;
		save_next = tmp->next;
		tmp->next = new;
		new->next = save_next;
	}
}
