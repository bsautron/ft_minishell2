/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:13:17 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/09 16:41:41 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*start;
	t_list		*curr;

	start = f(lst);
	lst = lst->next;
	curr = start;
	while (lst != NULL)
	{
		curr->next = f(lst);
		curr = curr->next;
		lst = lst->next;
	}
	return (start);
}
