/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_or_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 00:43:45 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/28 14:03:15 by bsautron         ###   ########.fr       */
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

char		*ft_join_or_del(char *cmd, char *c, char cac)
{
	c[0] = cac;
	c[1] = '\0';
	if (cac != 127)
	{
		ft_putchar(cac);
		cmd = ft_strjoin(cmd, c);
	}
	else
		cmd = ft_delone(cmd);
	return (cmd);
}
