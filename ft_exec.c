/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 02:25:48 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/27 03:07:52 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_error(pid_t child, char *cmd, int sig)
{
	if (sig == SIGSEGV)
	{
		ft_putnbr_fd(child, 2);
		ft_putstr_fd(" segmentation fault ", 2);
		ft_putendl_fd(cmd, 2);
		return (-1);
	}
	if (sig == 10)
	{
		ft_putnbr_fd(child, 2);
		ft_putstr_fd(" bus error ", 2);
		ft_putendl_fd(cmd, 2);
		return (-1);
	}
	return (0);

}

int			ft_exec(char *bin, char *cmd, char **env)
{
	pid_t		child;
	int			status;

	child = fork();
	if (child < 0)
		return (-1);
	if (child > 0)
	{
		signal(SIGINT, ft_stop);
		if (g_stop == 1)
			kill(child, SIGINT);
		g_stop = 0;
		waitpid(child, &status, 0);
	}
	else
	{
		execve(bin, ft_strsplit_whitespace(cmd), env);
		exit(-1);
	}
	if (ft_error(child, cmd, WTERMSIG(status)) == -1)
		return (-1);
	return (WEXITSTATUS(status));
}
