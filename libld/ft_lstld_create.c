/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 09:04:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 15:12:54 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libld.h"

t_lstld	*ft_lstld_create(char *str)
{
	t_lstld	*new;

	new = (t_lstld *)malloc(sizeof(t_lstld));
	new->str = ft_strdup(str);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
