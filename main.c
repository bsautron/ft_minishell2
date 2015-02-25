/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:56:35 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 08:30:47 by bsautron         ###   ########.fr       */
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
	t_lstl	*lenv;
	char	*cmd;

	ft_attrape_moi_si_tu_peux();
	if (env[0])
	{
		lenv = ft_get_var_env(env);
		while (1)
		{
			cmd = ft_prompt(lenv);
			dprintf(1, "\n%s\n", cmd);
		}
	}
	ft_tcg(1);
	free(cmd);
	(void)argc;
	(void)argv;
	return (0);
}
