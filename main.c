/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:21:58 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/28 12:28:10 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

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

static void	ft_tcg(char f)
{
	static int				fd;
	static struct termios	term_attributes;

	fd = STDOUT_FILENO;
	if (f == 0)
	{
		tcgetattr(fd, &term_attributes);
		term_attributes.c_lflag = term_attributes.c_lflag & ~ICANON;
		term_attributes.c_lflag = term_attributes.c_lflag
			& ~(ECHOK | ECHO | ECHONL | ECHOE | IEXTEN);
		term_attributes.c_cc[VMIN] = 1;
		term_attributes.c_cc[VTIME] = 0;
		tcsetattr(fd, TCSADRAIN, &term_attributes);
	}
	else
	{
		term_attributes.c_lflag = term_attributes.c_lflag | ICANON;
		term_attributes.c_lflag = term_attributes.c_lflag | ECHO;
		tcsetattr(fd, TCSADRAIN, &term_attributes);
	}
}

int			main(int argc, char **argv, char **env)
{
	char			**saint_env;

	(void)argc;
	(void)argv;
	ft_heisenberg();
	signal(SIGINT, ft_stop);
	ft_tcg(0);
	if (ft_nb_env(env))
	{
		//ft_setenv(&env, "OLDPWD= ");
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
