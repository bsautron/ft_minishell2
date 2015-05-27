/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scope_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 08:38:03 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/25 19:17:48 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scope.h>

void	ft_scope_free(t_scope **begin)
{
	t_scope	*tmp;
	t_scope	*save;

	tmp = *begin;
	while (tmp)
	{
		save = tmp;
		tmp = tmp->next;
		free(save);
		save = NULL;
	}
	*begin = NULL;
}
