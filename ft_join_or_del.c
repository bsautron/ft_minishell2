/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_or_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 00:43:45 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/05 15:03:58 by bsautron         ###   ########.fr       */
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

char		*ft_join_or_del(char *cmd, char *c, char cac, int *pos)
{
	char	*befor;
	char	*after;

	c[0] = cac;
	c[1] = '\0';
	befor = ft_strdup(cmd);
	befor[*pos] = '\0';
	after = &cmd[*pos];
	if (cac != 127)
	{
		//ft_putchar(cac);
		befor = ft_strjoin(befor, c);
		cmd = ft_strjoin(befor, after);
		(*pos)++;
	}
	else
	{
		cmd = ft_delone(cmd);
		(*pos)--;
	}
	return (cmd);
}
