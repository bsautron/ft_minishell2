/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstld_get_link_by_id.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 02:11:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/01 02:11:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_lstld	*ft_lstld_get_link_by_id(t_lstld *list, size_t id)
{
	size_t		i;

	i = 0;
	while (list && i++ < id)
		list = list->next;
	return (list);
}
