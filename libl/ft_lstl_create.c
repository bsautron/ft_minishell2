/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 09:04:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 09:04:25 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libl.h"

t_lstl	*ft_lstl_create(char *str)
{
	t_lstl	*new;

	new = (t_lstl *)malloc(sizeof(t_lstl));
	new->str = ft_strdup(str);
	new->next = NULL;
	return (new);
}
