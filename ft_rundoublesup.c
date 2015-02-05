/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rundoublesup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 22:15:54 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/04 22:16:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_rundoublesup(char *cmd, char **env)
{
	pid_t	child;
	int		status;
	int		fd;
	char	*filename;
	char	*befor;
	char	**path;
	int		i;

	filename = ft_strtrim(ft_strchr(cmd, '>') + 2);
	befor = ft_strtrim(ft_rstrchr(cmd, '>'));
	path = ft_getpath(env);
	i = 0;
	while (path[i] && !ft_cmd_is_in_path(ft_getcmd(befor), path[i]))
		i++;
	befor = ft_strjoin(ft_strjoin(path[i], "/"), befor);
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
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
		if (ft_strequ(ft_getcmd(befor), "pwd"))
			ft_putendl(ft_pwd());
		else if (ft_strequ(ft_getcmd(befor), "env"))
			ft_env(&env, ft_strdup(befor + ft_strlen(befor)), ft_getpath(env), 0);
		else
			execve(ft_getcmd(befor), ft_strsplit_whitespace(befor), env);
	}
	exit(0);
}
