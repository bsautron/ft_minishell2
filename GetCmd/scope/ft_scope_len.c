/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scope_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:43:55 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/23 18:37:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scope.h>

int		ft_scope_len(t_scope *list)
{
	int		len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
