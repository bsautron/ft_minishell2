/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:01:48 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/11 08:10:54 by bsautron         ###   ########.fr       */
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
			free(tab[i++]);
		free(tab);
		return (1);
	}
	free(*tab);
	free(tab);
	return (0);
}

static int	ft_builtins(char *cmd, char ***env, int rt)
{
	int		ret;
	char	*after;
	char	*the_cmd;

	ret = rt;
	the_cmd = ft_getcmd(cmd);
	if (ft_onlyesp(cmd))
		return (rt);
	after = ft_strdup(cmd + ft_strlen(the_cmd));
	if (ft_strequ(the_cmd, "exit"))
		ret = ft_exit(after);
	else if (ft_strequ(the_cmd, "env"))
		ret = ft_exec(cmd, *env);
	else if (ft_strequ(the_cmd, "cd"))
		ret = ft_cd(env, after);
	else if (ft_strequ(the_cmd, "pwd"))
		ret = ft_exec(cmd, *env);
	else if (ft_strequ(the_cmd, "setenv"))
		ret = ft_setenv(env, after);
	else if (ft_strequ(the_cmd, "unsetenv"))
		ret = ft_unsetenv(env, after);
	else if (!ft_onlyesp(cmd))
		ret = 1;
	free(the_cmd);
	return (ret);
}

int			ft_what(char *cmd, char ***env, int rt)
{
	int		ret;

	ret = rt;
	cmd = ft_strtrim_new(cmd);
	if (cmd)
	{
		if ((ret = ft_builtins(cmd, env, rt)) == -1)
			return (1);
		else if (!ft_onlyesp(cmd) && ret == 1)
		{
			ret = ft_exec(cmd, *env);
			return (ret);
		}
	}
	return (ret);
}
