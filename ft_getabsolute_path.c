/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getabsolute_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 17:17:42 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/11 07:35:45 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_fuckyou(char *cmd)
{
	ft_putstr_fd("ft_sh: command not found: ", 2);
	ft_putendl_fd(ft_getcmd(cmd), 2);
	return (1);
}

static int	ft_saydenied(char *cmd)
{
	ft_putstr_fd("ft_sh: persmission denied: ", 2);
	ft_putendl_fd(ft_getcmd(cmd), 2);
	return (1);
}

char	*ft_getabsolute_path(char *cmd, char **env, char say_error)
{
	int		i;
	int		id;
	char	**path;

	if (!ft_isbultin(ft_getcmd(cmd)) && (id = ft_get_id_var(env, "PATH")) != -1)
	{
		i = 0;
		path = ft_getpath(env);
		while (path[i] && !ft_cmd_is_in_path(ft_getcmd(cmd), path[i]))
			i++;
		if (!path[i])
		{
			//free path
			if (access(ft_getcmd(cmd), X_OK) == 0)
			{
				return (cmd);
			}
			else if (say_error)
				ft_saydenied(cmd);
			else if (say_error && ft_fuckyou(cmd))
				return (NULL);
			return (NULL);
		}
		else
		{
			//free path
			return (ft_strjoin(ft_strjoin(path[i], "/"), cmd));
		}
	}
	return (cmd);
}
