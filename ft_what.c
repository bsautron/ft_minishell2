/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:01:48 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/04 21:14:43 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_exit(char *after)
{
	char	**tab;
	int		i;

	tab = ft_strsplit_white_space(after);
	if (ft_nb_env(tab) < 2)
	{
		if (ft_strlen(after))
			exit(ft_atoi(after));
		else
			exit(0);
	}
	else
	{
		ft_putendl_fd("exit: too many arguments", 2);
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		return (1);
	}
	free(*tab);
	free(tab);
	return (0);
}

/*
 * bulting need fork();
 */

static int	ft_builtins(char *cmd, char ***env, char **path, int rt)
{
	int		ret;
	char	*after;
	char	*the_cmd;

	ret = rt;
	the_cmd = ft_getcmd(cmd);
	(void)path;
	if (ft_onlyesp(cmd))
		return (rt);
	after = ft_strdup(cmd + ft_strlen(the_cmd));
	if (ft_strequ(the_cmd, "exit"))
		ret = ft_exit(after);
	else if (ft_strequ(the_cmd, "env"))
		ret = ft_exec("env", cmd, *env);
	else if (ft_strequ(the_cmd, "cd"))
		ret = ft_cd(env, after);
	else if (ft_strequ(the_cmd, "pwd"))
		ret = ft_exec("pwd", cmd, *env);
	else if (ft_strequ(the_cmd, "export"))
		ret = ft_setenv(env, after);
	else if (ft_strequ(the_cmd, "unset"))
		ret = ft_unsetenv(env, after);
	else if (!ft_onlyesp(cmd))
		ret = 1;
	free(the_cmd);
	return (ret);
}

static int	ft_fuckyou(char *cmd, char ***env)
{
	if (access(ft_getcmd(cmd), X_OK) == 0)
		return (ft_exec(ft_getcmd(cmd), cmd, *env));
	else
	{
		ft_putstr_fd("ft_sh1: command not found: ", 2);
		ft_putendl_fd(ft_getcmd(cmd), 2);
		return (1);
	}
}

int			ft_what(char *cmd, char ***env, char **path, int rt)
{
	int		ret;
	int		i;

	i = 0;
	ret = rt;
	cmd = ft_strtrim_new(cmd);
	if (cmd)
	{
		if ((ret = ft_builtins(cmd, env, path, rt)) == -1)
			return (1);
		else if (!ft_onlyesp(cmd) && ret == 1)
		{
			while (path[i] && !ft_cmd_is_in_path(ft_getcmd(cmd), path[i]))
				i++;
			if (!path[i])
				ret = ft_fuckyou(cmd, env);
			else if (path[i] && !ft_strequ(ft_getcmd(cmd), "env"))
			{
				ret = ft_exec(ft_strjoin(ft_strjoin(path[i], "/"),
							ft_getcmd(cmd)), cmd, *env);
				return (ret);
			}
		}
	}
	return (ret);
}
