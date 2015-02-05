/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runpipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 22:10:58 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/04 23:56:10 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_runpipe(char *cmd, char **env)
{
	pid_t	child;
	int		status;
	int		fildes[2];
	char	*befor;
	char	*after;
	char	**path;
	int		i;

	i = 0;
	path = ft_getpath(env);
	befor = ft_strtrim(ft_rstrchr(cmd, '|'));
	after = ft_strtrim(ft_rstrchr(ft_strchr(cmd, '|') + 1, '|'));
	while (path[i] && !ft_cmd_is_in_path(ft_getcmd(befor), path[i]))
		i++;
	befor = ft_strjoin(ft_strjoin(path[i], "/"), befor);
	i = 0;
	while (path[i] && !ft_cmd_is_in_path(ft_getcmd(after), path[i]))
		i++;
	after = ft_strjoin(ft_strjoin(path[i], "/"), after);
	pipe(fildes);
	child = fork();
	if (child < 0)
		exit(1);
	if (!IS_CHILD(child))
	{
		CATCH_SIG;
		close(fildes[1]);
		dup2(fildes[0], 0);
		close(fildes[0]);
		if (ft_first_redir(ft_strchr(cmd, '|') + 1) == '|')
			ft_runpipe(ft_strchr(cmd, '|') + 1, env);
		else if (ft_first_redir(ft_strchr(cmd, '|') + 1) == '>')
			ft_runsup(ft_strchr(cmd, '|') + 1, env, 0);
		else if (ft_first_redir(ft_strchr(cmd, '|') + 1) == '<')
			ft_runinf(ft_strchr(cmd, '|') + 1, env);
		else if (ft_first_redir(ft_strchr(cmd, '|') + 1) == '.')
			ft_rundoublesup(ft_strchr(cmd, '|') + 1, env);
		execve(ft_getcmd(after), ft_strsplit_whitespace(after), env);
	}
	else
	{
		close(fildes[0]);
		dup2(fildes[1], 1);
		close(fildes[1]);
		execve(ft_getcmd(befor), ft_strsplit_whitespace(befor), env);
	}
	exit(WEXITSTATUS(status));
}
