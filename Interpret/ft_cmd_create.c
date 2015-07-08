/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 09:04:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/08 06:10:24 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interpret.h>

t_cmd	*ft_cmd_create(char ***cmd, char **bin, int type)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->cmd = *cmd;
	new->bin = *bin;
	new->type = type;
	new->next = NULL;
	return (new);
}
