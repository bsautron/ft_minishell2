/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:43:55 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/24 19:45:17 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libl.h"

int		ft_lstl_len(t_lstl *list)
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
