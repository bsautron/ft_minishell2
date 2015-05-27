/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scope_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 09:04:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/23 18:33:15 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scope.h>

t_scope	*ft_scope_create(int id)
{
	t_scope	*new;

	new = (t_scope *)malloc(sizeof(t_scope));
	new->id = id;
	new->next = NULL;
	return (new);
}
