/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:56:35 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/26 05:25:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static t_lstl	*ft_get_var_env(char **env)
{
	t_lstl	*lenv;

	lenv = NULL;
	while (*env)
	{
		ft_lstl_add_back(&lenv, *env);
		env++;
	}
	return (lenv);
}

static void		ft_attrape_moi_si_tu_peux(void)
{
	signal(SIGINT, ft_signal_handler);
}

static void		ft_get_history(t_env *env)
{
	char	*line;
	int		fd;

	if ((fd = open(env->path_h, O_CREAT | O_RDONLY, 0600)) != -1)
	{
		while (get_next_line(fd, &line) > 0)
			ft_lstld_add(&env->history, line);
		close(fd);
	}
}

int				main(int argc, char **argv, char **env)
{
	t_env	tenv;
	char	*cmd;
	char	*home;

	ft_bzero(&tenv, sizeof(t_env));
	ft_attrape_moi_si_tu_peux();
	tenv.list_env = ft_get_var_env(env);
	if ((home = ft_get_env("HOME=", &tenv)) != NULL)
		tenv.path_h = ft_strjoin(home, HISTORY_FILE);
	else
		tenv.path_h = ft_strjoin(ft_pwd(), HISTORY_FILE);
	ft_get_history(&tenv);
	while (1)
	{
		cmd = ft_prompt(&tenv);
		cmd = ft_parser(cmd, &tenv);
		ft_putstr("\ncmd = ");
		ft_putstr(cmd);
		ft_putchar('\n');
		if (ft_strequ(cmd, "env"))
			ft_lstl_print(tenv.list_env);
		free(cmd);
	}
	ft_lstl_free(&tenv.list_env);
	ft_reset_term();
	(void)argc;
	(void)argv;
	return (0);
}
