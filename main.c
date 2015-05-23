/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:56:35 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/10 00:03:56 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_env		g_env;

static t_lstl	*ft_get_var_env(char **env)
{
	t_lstl	*lenv;
	int		i;

	i = 0;
	lenv = NULL;
	while (env[i])
	{
		ft_lstl_add_back(&lenv, env[i]);
		i++;
	}
	return (lenv);
}

static void		ft_attrape_moi_si_tu_peux(void)
{
	signal(SIGINT, ft_signal_handler);
	signal(SIGWINCH, ft_signal_handler);
}

static void		ft_get_history(void)
{
	char	*line;
	int		fd;

	line = NULL;
	if ((fd = open(g_env.path_h, O_CREAT | O_RDONLY, 0600)) != -1)
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_lstld_add(&g_env.history, line);
			if (line)
				free(line);
		}
		close(fd);
	}
}

static void		ft_init_env(char **env)
{
	char	*home;

	ft_bzero(&g_env, sizeof(t_env));
	g_env.list_env = ft_get_var_env(env);
	if ((home = ft_get_env("HOME=")) != NULL)
		g_env.path_h = ft_strjoin(home, HISTORY_FILE);
	else
		g_env.path_h = ft_strjoin(ft_pwd(), HISTORY_FILE);
	ft_get_history();
}

int				main(int argc, char **argv, char **env)
{
	char	*cmd;

	ft_signal_handler(SIGWINCH);
	ft_attrape_moi_si_tu_peux();
	ft_init_env(env);
	while (1)
	{
		cmd = ft_get_cmd();
		//cmd = ft_parser(cmd, &tenv);
		ft_putstr("\ncmd = ");
		ft_putstr(cmd);
		ft_putchar('\n');
		if (ft_strequ(cmd, "env"))
		{
			ft_lstl_print(g_env.list_env);
			ft_putchar('\n');
		}
		free(cmd);
	}
	ft_reset_term();
	(void)argc;
	(void)argv;
	return (0);
}
