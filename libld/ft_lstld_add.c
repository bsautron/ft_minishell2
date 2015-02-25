/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:03:59 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 15:21:43 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libld.h"

void	ft_lstld_add(t_lstld **begin, char *str)
{
	t_lstld	*new;

	new = ft_lstld_create(str);
	if (!(*begin))
		*begin = new;
	else
	{
		new->next = *begin;
		(*begin)->prev = new;
		*begin = new;
	}
}
