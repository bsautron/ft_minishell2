/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:20:38 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/28 12:26:16 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_launcher(char **tab_cmd, int *ret, char ***env, char **path)
{
	int		i;

	i = 0;
	while (tab_cmd[i])
	{
		*ret = ft_what(tab_cmd[i], env, path, *ret);
		i++;
	}
}

int			ft_cmd(char **env)
{
	char	*cmd;
	int		ret;
	char	**path;
	char	**tab_cmd;

	ret = 0;
	path = NULL;
	while (1)
	{
		if (path)
		{
			free(path);
		}
		path = ft_getpath(env);
		if (path == NULL)
		{
			path = (char **)malloc(sizeof(char *) * 2);
			path[0] = ft_strdup("");
			path[1] = NULL;
		}
		dprintf(1, "%s", "");
		cmd = ft_prompt(env, ret);
		tab_cmd = ft_strsplit(cmd, ';');
		ft_launcher(tab_cmd, &ret, &env, path);
		free(path);
		path = NULL;
		free(tab_cmd);
	}
	return (0);
}
