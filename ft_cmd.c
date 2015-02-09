/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:20:38 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/09 05:46:48 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

/*static void	ft_lexeur(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		
		i++;
	}
}*/

static void	ft_launcher(char **tab_cmd, int *ret, char ***env, char **path)
{
	int		i;
	int		j;
	int		k;
	char	**tab_and;
	char	**tab_or;

	i = 0;
	while (tab_cmd[i] && !ft_onlyesp(tab_cmd[i]))
	{
		j = 0;
		*ret = 0;
		tab_and = ft_strsplit_str(tab_cmd[i], "&&");
		while (tab_and[j] && *ret == 0)
		{
			k = 0;
			*ret = 1;
			tab_or = ft_strsplit_str(tab_and[j], "||");
			while (tab_or[k] && *ret != 0)
			{
				*ret = ft_what(tab_or[k], env, path, *ret);
				k++;
			}
			j++;
		}
		// faudra free
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
		cmd = ft_prompt(env, ret);
		tab_cmd = ft_strsplit(cmd, ';');
		ft_launcher(tab_cmd, &ret, &env, path);
		free(path);
		path = NULL;
		free(tab_cmd);
		//free(cmd);
	}
	return (0);
}
