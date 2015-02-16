/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_or_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 00:43:45 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/11 07:37:35 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static char	*ft_delone(char *cmd)
{
	if (ft_strlen(cmd) > 0)
	{
		if (cmd[ft_strlen(cmd) - 1] == '\t')
			ft_nclear(4);
		else
			ft_nclear(1);
		cmd[ft_strlen(cmd) - 1] = '\0';
	}
	return (cmd);
}

char		*ft_join_or_del(char *cmd, char *cac, int *pos)
{
	char	*befor;
	char	*after;
	char	c[2];

	c[0] = cac[0];
	c[1] = '\0';
	befor = ft_strdup(cmd);
	befor[*pos] = '\0';
	after = &cmd[*pos];
	if (*cac != 127)
	{
		befor = ft_strjoin(befor, c);
		cmd = ft_strjoin(befor, after);
		(*pos)++;
	}
	else
	{
		cmd = ft_delone(cmd);
		if (ft_strlen(cmd) > 0)
		{
			ft_nclear(1);
			(*pos)--;
		}
	}
	return (cmd);
}
