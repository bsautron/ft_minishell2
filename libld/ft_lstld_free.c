/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 08:38:03 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/09 22:54:52 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libld.h"

void	ft_lstld_free(t_lstld **begin)
{
	t_lstld	*tmp;
	t_lstld	*save;

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
