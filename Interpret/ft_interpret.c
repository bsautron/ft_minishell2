/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:45:19 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/10 09:58:22 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

#define RW_WRITE		0
#define RW_READ			1

static int	ft_count_pipe(t_token *tk, int *fd, int *rw)
{
	int		i;
	int		file;
	int		mode;

	i = 0;
	file = 0;
	while (tk)
	{
		if (tk->type == TK_PIPE)
			i++;
		if (file == 1)
		{
			*fd = open(tk->value, mode, 0644);
			file = 0;
		}
		if (tk->type == TK_LEFT_REDIRECTION)
		{
			file = 1;
			mode = O_WRONLY | O_CREAT | O_TRUNC;
			*rw = RW_WRITE;
		}
		else if (tk->type == TK_DLEFT_REDIRECTION)
		{
			file = 1;
			mode = O_WRONLY | O_CREAT | O_APPEND;
			*rw = RW_WRITE;
		}
		else if (tk->type == TK_RIGHT_REDIRECTION)
		{
			file = 1;
			mode = O_RDONLY;
			*rw = RW_READ;
		}
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

static char	*ft_get_where_bin(char *cmd, t_lstl *lenv)
{
	char	**path;
	int		i;
	char	*tmp;
	char	*tmp2;

	path = ft_strsplit(ft_get_lenv(lenv, "PATH="), ':');
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, X_OK) == 0)
			return (tmp2);
		free(tmp2);
		i++;
	}
	return (0);
}

static int	ft_get_type_bultin(char *bin)
{
	char	*tab[NB_BULTINS + 2];
	int		i;

	tab[-1 + TB_PWD] = PWD;
	tab[-1 + TB_SETENV] = SETENV;
	tab[-1 + TB_ENV] = ENV;
	tab[-1 + TB_NOFORK] = "";
	tab[NB_BULTINS + 1] = NULL;
	i = 0;
	while (tab[i])
	{
		if (ft_strequ(tab[i], bin))
			return (i + 1);
		i++;
	}
	return (0);
}

int		ft_interpret(t_token *tk, t_lstl **lenv)
{
	int		l;
	char	**cmd;
	char	*bin;
	t_lstl	*tmp;
	t_cmd	*lall_cmd;
	int		nb_pipes;
	int		type;
	int		fd;
	int		rw;

	nb_pipes = ft_count_pipe(tk, &fd, &rw);
	lall_cmd = NULL;
	while (tk)
	{
		l = 0;
		tmp = NULL;
		while (tk && tk->type == TK_CMD_ARG)
		{
			ft_lstl_add_back(&tmp, tk->value);
			tk = tk->next;
			l++;
		}
		cmd = ft_lstl_to_tab(tmp); 
		bin = ft_get_where_bin(cmd[0], *lenv);
		type = ft_get_type_bultin(cmd[0]);
		if (bin == NULL && type == 0)
			type = -1;
		ft_cmd_add_back(&lall_cmd, ft_cmd_create(&cmd, &bin, type));
		if (tk)
			tk = tk->next;
	}

	pid_t	child;
	int		status;
	int		i_pipe;
	int		i;
	int		j;
	int		*pipesfd;
	t_lstl	**all_cmd;
	char	**env;
	//	char	**cmd;

	/*
	   all_cmd = (t_lstl **)malloc(sizeof(t_lstl *) * (nb_pipes + 2));
	   for (int k = 0; k < nb_pipes + 1; k++)
	   {
	   all_cmd[k] = 0;
	   for (int l = 0; tk && !ft_strequ(tk->value, "|"); l++)
	   {
	   ft_lstl_add_back(&all_cmd[k], tk->value);
	   if (l == 0)
	   all_cmd[k]->str = ft_get_where_bin(&all_cmd[k], env);
	   tk = tk->next;
	   }
	   if (tk)
	   tk = tk->next;
	   }
	   all_cmd[nb_pipes + 1] = 0;
	   */
	i_pipe = 0;
	pipesfd = (int *)malloc(sizeof(int) * (2 * nb_pipes + 1));
	while (i_pipe < nb_pipes)
	{
		pipe(pipesfd + 2 * i_pipe);
		i_pipe++;
	}
	i = 0;
	env = ft_lstl_to_tab(*lenv);
	while (i < nb_pipes + 1)
	{
		if (lall_cmd->type < TB_NOFORK)
		{
			child = fork();
			if (child < 0)
			{
				dprintf(2, "%s\n", "FAIIIL");
				return (-1);
			}
			if (child == 0)
			{
				if (i != nb_pipes)
					dup2(pipesfd[2 * i + 1], 1);
				else if (rw == RW_WRITE)
					dup2(fd, 1);
				else if (rw == RW_READ)
					dup2(fd, 0);
				if (i != 0)
					dup2(pipesfd[2 * i - 2], 0);
				j = 0;
				while (j < nb_pipes)
					close(pipesfd[2 * j++ + 1]);
				//pas avec all_cmd[0], regarde dans ps le nom
				if (lall_cmd->type == TB_DEFAULT)
					execve(lall_cmd->bin, lall_cmd->cmd, env);
				else if (lall_cmd->type == -1)
				{
					ft_putstr_fd("ft_minishell: command not found: ", 2);
					ft_putendl_fd(lall_cmd->cmd[0], 2);
				}
				else
					ft_exec_bultin(lall_cmd, lenv);
				exit(0);
			}
		}
		else
			ft_exec_bultin(lall_cmd, lenv);
		lall_cmd = lall_cmd->next;
		i++;
	}
	j = 0;
	while (j < 2 * nb_pipes)
		close(pipesfd[j++]);
	j = 0;
	while (j < nb_pipes + 1)
	{
		wait(&status);
		j++;
	}
	close(fd);
	// free all_cmd
	// */
	return (WEXITSTATUS(status));
}
