/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:52:49 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/24 19:53:26 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libl.h"

void	ft_lstl_delone(t_lstl **begin, char *str, int (*f)(char const *, char const *))
{
	t_lstl	*tmp;

	tmp = *begin;
	if (tmp && f(str, tmp->str))
		*begin = tmp->next;
	while (tmp && tmp->next && !f(str, tmp->next->str))
		tmp = tmp->next;
	if (tmp && tmp->next && tmp->next->next)
		tmp->next = tmp->next->next;
	else if (tmp && tmp->next && f(str, tmp->next->str))
		tmp->next = NULL;
}

