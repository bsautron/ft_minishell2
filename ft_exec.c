/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:45:19 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/02 17:13:07 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>


static int	ft_count_pipe(t_token *tk)
{
	int		i;

	i = 0;
	while (tk)
	{
		if (tk->type == TK_PIPE)
			i++;
		tk = tk->next;
	}
	return (i);
}

static char		**ft_getcmd_pipe(char **all_cmd)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	while (all_cmd && all_cmd[i] && !ft_strequ(all_cmd[i], "|"))
		i++;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	j = 0;
	while (j < i)
	{
		tab[j] = ft_strdup(all_cmd[j]);
		j++;
	}
	tab[j] = 0;
	return (tab);
}

int		ft_exec(t_token *tk, char **env)
{
	pid_t	child = 0;
	int		status;
	int		nb_pipes;
	int		i_pipe;
	int		i;
	int		j;
	int		*pipesfd;
	char	**all_cmd;
	char	**cmd;

	nb_pipes = ft_count_pipe(tk);
	pipesfd = (int *)malloc(sizeof(int) * (2 * nb_pipes + 1));
	pipesfd[2 * nb_pipes] = 0;
	i_pipe = 0;
	while (i_pipe < 2 * nb_pipes)
	{
		pipe(pipesfd + 2 * i_pipe);
		i_pipe++;
	}
	all_cmd = ft_tk_to_tab(tk);
	i = 0;
	while (i < nb_pipes + 1)
	{
		child = fork();
		if (child < 0)
			return (-1);
		if (child == 0)
		{
			if (i != nb_pipes)
				dup2(pipesfd[2 * i + 1], 1);
			if (i != 0)
				dup2(pipesfd[2 * i - 2], 0);
			j = 0;
			while (j < nb_pipes)
				close(pipesfd[2 * j++]);
			cmd = ft_getcmd_pipe(all_cmd);
			execve(ft_strjoin("/bin/", cmd[0]), cmd, env);
		}
		while (all_cmd && *all_cmd && !ft_strequ(*all_cmd, "|"))
			all_cmd++;
		if (all_cmd)
			all_cmd++;
		i++;
	}
	j = 0;
	while (j < nb_pipes)
		close(pipesfd[2 * j++]);
	j = 0;
	while (j++ < nb_pipes)
		wait(&status);
	return (WEXITSTATUS(status));
}
