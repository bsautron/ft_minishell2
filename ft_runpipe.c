/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runpipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 22:10:58 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/09 06:02:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_runpipe(char *cmd, char **env)
{
	pid_t	child;
	int		status;
	int		fildes[2];
	char	*befor;

	befor = ft_strtrim(ft_rstrchr(cmd, '|'));
	befor = ft_getabsolute_path(befor, env, 1);

	pipe(fildes);
	//dprintf(1, "fd[0] = %d, fd[1] = %d\n", fildes[0], fildes[1]);
	child = fork();
	if (child < 0)
		exit(1);
	if (!IS_CHILD(child))
	{
		//dprintf(2, "%s\n", "PAPA pipe");
		CATCH_SIG;

		close(fildes[0]);
		dup2(fildes[1], 1);
		ft_exec(ft_strtrim(ft_rstrchr(cmd, '|')), env);

	}
	else
	{
		//dprintf(2, "%s\n", "FILS pipe");
		close(fildes[1]);
		dup2(fildes[0], 0);
		if (ft_first_redir(ft_strchr(cmd, '|') + 1) == '|')
			ft_runpipe(ft_strchr(cmd, '|') + 1, env);
		else if (ft_first_redir(ft_strchr(cmd, '|') + 1) == '>')
			ft_runsup(ft_strchr(cmd, '|') + 1, env, 0);
		else if (ft_first_redir(ft_strchr(cmd, '|') + 1) == '<')
			ft_runinf(ft_strchr(cmd, '|') + 1, env);
		else if (ft_first_redir(ft_strchr(cmd, '|') + 1) == '.')
			ft_rundoublesup(ft_strchr(cmd, '|') + 1, env);
		ft_exec(ft_strtrim(ft_rstrchr(ft_strchr(cmd, '|') + 1, '|')), env);
		exit(WEXITSTATUS(status));
	}
	exit(0);
}
