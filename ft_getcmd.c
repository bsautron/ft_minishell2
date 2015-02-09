/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 23:41:51 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/09 05:43:56 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_getcmd(char *cmd)
{
	char	*dst;
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	while (cmd[i] && cmd[i] > ' ')
		i++;
	dst = ft_strsub(cmd, 0, i);
	if (dst)
		return (dst);
	return (ft_strdup(""));
}
