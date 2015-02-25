/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 08:38:03 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 10:27:23 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libl.h"

void	ft_lstl_free(t_lstl **begin)
{
	t_lstl	*tmp;
	t_lstl	*save;

	tmp = *begin;
	while (tmp)
	{
		save = tmp;
		tmp = tmp->next;
		free(save->str);
		free(save);
		save = NULL;
	}
}
