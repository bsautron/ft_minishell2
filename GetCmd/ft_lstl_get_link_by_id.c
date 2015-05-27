/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_get_link_by_id.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 02:23:16 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/01 02:23:33 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_lstl *ft_lstl_get_link_by_id(t_lstl *list, size_t id)
{
	size_t          i;

	i = 0;
	while (list && i++ < id)
		list = list->next;
	return (list);
}
