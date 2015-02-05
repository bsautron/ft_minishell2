/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runsup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 22:12:31 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/04 23:55:37 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_runsup(char *cmd, char **env, char flag)
{
	pid_t	child;
	int		status;
	int		fd;
	char	*filename;
	char	*befor;
	char	**path;
	int		i;

	i = 0;
	filename = ft_strtrim(ft_rstrchr(ft_strchr(cmd, '>') + 1, '>'));
	if (flag == 0)
	{
		befor = ft_strtrim(ft_rstrchr(cmd, '>'));
		path = ft_getpath(env);
		while (path[i] && !ft_cmd_is_in_path(ft_getcmd(befor), path[i]))
			i++;
		befor = ft_strjoin(ft_strjoin(path[i], "/"), befor);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	child = fork();
	if (child < 0)
		exit(1);
	if (!IS_CHILD(child))
	{
		CATCH_SIG;
		close(fd);
		waitpid(child, &status, 0);
		exit(WEXITSTATUS(status));
	}
	else
	{
		dup2(fd, 1);
		//close(fd);
		if (ft_first_redir(ft_strchr(cmd, '>') + 1) == '|')
			ft_runpipe(ft_strchr(cmd, '>') + 1, env);
		else if (ft_first_redir(ft_strchr(cmd, '>') + 1) == '>')
			ft_runsup(ft_strchr(cmd, '>') + 1, env, 1);
		else if (ft_first_redir(ft_strchr(cmd, '>') + 1) == '<')
			ft_runinf(ft_strchr(cmd, '>') + 1, env);
		else if (ft_first_redir(ft_strchr(cmd, '>') + 1) == '.')
			ft_rundoublesup(ft_strchr(cmd, '>') + 1, env);
		if (ft_strequ(ft_getcmd(befor), "pwd"))
			ft_putendl(ft_pwd());
		else if (ft_strequ(ft_getcmd(befor), "env"))
			ft_env(&env, ft_strdup(befor + ft_strlen(befor)), ft_getpath(env), 0);
		else if (flag == 0)
			execve(ft_getcmd(befor), ft_strsplit_whitespace(befor), env);
	}
	exit(0);
}
