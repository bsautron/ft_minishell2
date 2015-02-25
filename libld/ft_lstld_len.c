/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:43:55 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 20:30:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libld.h"

size_t	ft_lstld_len(t_lstld *list)
{
	size_t	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
