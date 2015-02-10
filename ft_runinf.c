/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runinf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 22:14:50 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/10 02:14:02 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static char	*ft_getfilename(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '|' && str[i] != '>' && str[i] != '<')
		i++;
	return (ft_strsub(str, 0, i));
}

void	ft_runinf(char *cmd, char **env)
{
	pid_t	child;
	int		status;
	int		fd;
	char	*filename;
	char	*befor;
	char	**path;
	int		i;

	path = ft_getpath(env);
	filename = ft_strtrim(ft_getfilename(ft_strchr(cmd, '<') + 1));
	befor = ft_getabsolute_path(cmd, env, 0);
	if ((fd = open(filename, O_RDONLY)) != -1)
	{
		child = fork();
		if (child < 0)
			exit(1);
		if (!IS_CHILD(child))
		{
			CATCH_SIG;
			waitpid(child, &status, 0);
			dup2(fd, 0);
			execve(ft_getcmd(befor), ft_strsplit_whitespace(befor), env);
		}
		else
		{
			close(fd);/*
			if (ft_first_redir(ft_strchr(cmd, '<') + 1) == '|')
				ft_runpipe(ft_strchr(cmd, '<') + 1, env);
			else if (ft_first_redir(ft_strchr(cmd, '<') + 1) == '<')
				ft_runsup(ft_strchr(cmd, '<') + 1, env, 0);
			else if (ft_first_redir(ft_strchr(cmd, '<') + 1) == '<')
				ft_runinf(ft_strchr(cmd, '<') + 1, env);
			else if (ft_first_redir(ft_strchr(cmd, '<') + 1) == '.')
				ft_rundoublesup(ft_strchr(cmd, '<') + 1, env);
			if (ft_strequ(ft_getcmd(befor), "pwd"))
				ft_putendl(ft_pwd());
			else if (ft_strequ(ft_getcmd(befor), "env"))
				ft_env(&env, ft_strdup(befor + ft_strlen(befor)), ft_getpath(env), 0);
			else*/
				execve(ft_getcmd(befor), ft_strsplit_whitespace(befor), env);
			exit(WEXITSTATUS(status));
		}
	}
	ft_putstr_fd("ft_minishell: no such file or directory: ", 2);
	ft_putendl_fd(filename, 2);
	exit(1);
}
