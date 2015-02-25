/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:56:35 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 13:26:35 by bsautron         ###   ########.fr       */
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

int				main(int argc, char **argv, char **env)
{
	t_env	tenv;
	char	*cmd;

	ft_bzero(&tenv, sizeof(t_env));
	ft_attrape_moi_si_tu_peux();
	if (env[0])
	{
		tenv.list_env = ft_get_var_env(env);
		while (1)
		{
			cmd = ft_prompt(&tenv);
			cmd = ft_parser(cmd, &tenv);
			ft_putstr("\ncmd = ");
			ft_putendl(cmd);
			free(cmd);
		}
		ft_lstl_free(&tenv.list_env);
	}

	ft_tcg(1);
	(void)argc;
	(void)argv;
	return (0);
}
