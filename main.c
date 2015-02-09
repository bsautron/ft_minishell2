/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:21:58 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/09 05:59:27 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <term.h>

static void	ft_heisenberg(void)
{
	ft_putendl("                         @EEEEEEEEEEEEESSEQ.");
	ft_putendl("                         EEEEEEEEEEEEEEEEE3L");
	ft_putendl("                        JEEEEEEEEEEEEEEEEEE[");
	ft_putendl("                        {EEEEEEEEEEEEEEEEEE1");
	ft_putendl("                        @EEEEEEEEEEEEEEEEEEQ.");
	ft_putendl("                  `*G@EEEEEEEEEEEEEEEEEEEEEEEEEEP*");
	ft_putendl("                        J1:::z:=c.;.=::z::JL");
	ft_putendl("                       E3@sSSSSS@sz@SSSSSb@Ed.");
	ft_putendl("                       \\3E$EEEEEEF3EEEEEEZQE[");
	ft_putendl("                        V$?5GGGRF::?5GGGP5$Q.:");
	ft_putendl("                        '$c..:.z:::::..:.:$F");
	ft_putendl("                          E)::;;Z2H5L;.;:3.");
	ft_putendl("                          J1J3E5E5EE51t[!F");
	ft_putendl("                           \"[L:::::.:::yF");
	ft_putendl("                             *c::::::;*");
	ft_putendl("                               `^**^`");
}

int			main(int argc, char **argv, char **env)
{
	char		**saint_env;

	(void)argc;
	(void)argv;
	ft_heisenberg();
	signal(SIGINT, ft_stop);
	if (ft_nb_env(env))
	{
		ft_setenv(&env, "OLDPWD= ");
		ft_cmd(env);
	}
	else
	{
		if ((saint_env = (char **)malloc(sizeof(char *) * 4)) != NULL)
		{
			saint_env[0] = ft_strjoin("PWD=", ft_pwd());
			saint_env[1] = ft_strdup("USER=bsautron");
			saint_env[2] = ft_strdup("PATH=/bin:/usr/bin");
			saint_env[3] = NULL;
			ft_cmd(saint_env);
		}
	}
	ft_tcg(1);
	return (0);
}
