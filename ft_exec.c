/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:45:19 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/09 23:42:15 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	ft_child(char *bin, char **tab, char **env)
{
	(void)bin;
	(void)tab;
	(void)env;
	dprintf(1, "%s\n", "dans CHILD");
	exit(0);
	return (0);
}

int		ft_exec(char *bin, char **tab, char **env)
{
	pid_t	child;
	int		status;

	child = fork();
	if (child == 0)
		ft_child(bin, tab, env);
	else
		waitpid(child, &status, 0);
	return (0);
}
