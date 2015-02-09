/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 06:10:48 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/09 06:16:22 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_isinpath(char *cmd, char **env)
{
	int		i;
	char	**path;

	path = ft_getpath(env);
	i = 0;
	while (path[i] && !ft_cmd_is_in_path(cmd, path[i]))
		i++;
	if (!path[i])
		return (0);
	return (1);
}
