/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 02:25:46 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/09 04:30:55 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#define NIQUE	char **history, char *cmd_saved, char *cmd

static void	ft_prompt2(char **env, int ret, int id_usr)
{
	char	*dirname;

	dirname = ft_get_dirname();
	if (ret == 0)
	{
		FLECHE;
		ft_putstr("\033[1;30;47m");
	}
	else
	{
		ft_putstr("\x1b[31m");
		FLECHE;
		ft_putstr("\033[1;31;47m");
	}
	if (id_usr != -1 && ft_strequ(dirname, &env[id_usr][5]))
		ft_putstr("~");
	else
		ft_putstr(dirname);
	ft_putstr("\033[0;37;40m ");
	free(dirname);
}

static void	ft_increm(int *i, int nb, char c)
{
	if (c == 'A')
	{
		(*i)--;
		if (*i < 0)
			*i = 0;
	}
	if (c == 'B')
	{
		(*i)++;
		if (*i > nb)
			*i = nb;
	}
}

static char	*ft_increm2(char c, NIQUE, int *i, int nb)
{
	if (c == 'A' || c == 'B')
	{
		if (c == 'A')
		{
			while (*i > 0
					&& (!ft_strnequ(cmd_saved, history[*i], ft_strlen(cmd_saved))
						|| ft_onlyesp(history[*i]) || ft_strequ(cmd, history[*i])))
				(*i)--;
		}
		else
		{
			while (*i < nb
					&& (!ft_strnequ(cmd_saved, history[*i], ft_strlen(cmd_saved))
						|| ft_onlyesp(history[*i]) || ft_strequ(cmd, history[*i])))
				(*i)++;
		}
		if (history[*i] && ft_strnequ(cmd_saved, history[*i],
					ft_strlen(cmd_saved)))
			cmd = ft_strdup(history[*i]);
		else
			cmd = ft_strdup(cmd_saved);
	}
	return (cmd);
}
/*
   static void	ft_mouv_lr(char c, int *pos)
   {
   if (c == 'D')
   {
   ft_putstr("\033[1D");
   (*pos)--;
   }
   if (c == 'C')
   {
   ft_putstr("\033[1C");
   (*pos)++;
   }
   }
   */

static void	ft_print_cmd(char *cmd, char **env)
{
	if (!ft_strequ(ft_getabsolute_path(cmd, env, 0), cmd))
		ft_putstr("\033[32m");
	else if (ft_isbultin(ft_getcmd(cmd)))
		ft_putstr("\033[33m");
	else
		ft_putstr("\033[31m");
	ft_putstr(ft_getcmd(cmd));
	ft_putstr("\033[0m");
	ft_putstr(cmd + ft_strlen(ft_getcmd(cmd)));
}

static char	*ft_gnlr(char *path_h, char *cmd, char *cmd_saved, char **env)
{
	int			nb;
	char		c[2];
	char		cac[3];
	int			i;
	int			j;
	char		**history;
	int			pos;

	nb = 0;
	i = 0;
	pos = 0;
	ft_bzero(cac, sizeof(char));
	history = ft_make_history(&nb, &i, path_h);
	while (cac[0] != '\n')
	{
		read(0, cac, 3);
		if (cac[0] == '\033')
		{
			if (cac[2] == 'A' || cac[2] == 'B')
			{
				ft_increm(&i, nb, cac[2]);
				ft_nclear(ft_strlen(cmd));
				cmd = ft_increm2(cac[2], history, cmd_saved, cmd, &i, nb);
				pos = ft_strlen(cmd);

			}
			else if (cac[2] == 'D' || cac[2] == 'C')
			{
				ft_putstr(cac);
				//ft_mouv_lr(*c, &pos);
			}
		}
		else
		{
			//ft_putstr(cac);
			cmd = ft_join_or_del(cmd, c, *cac, &pos);
			ft_nclear(ft_strlen(cmd) - 1);
			cmd_saved = ft_strdup(cmd);
		}
		ft_print_cmd(cmd, env);
	}
	j = 0;
	while (history[j])
	{
		free(history[j]);
		j++;
	}
	free(history);
	return (cmd);
}

char		*ft_prompt(char **env, int ret)
{
	char			*cmd;
	int				id_usr;
	int				fd;
	char			*path_h;

	ft_tcg(0);
	if (env && ft_get_id_var(env, "HOME") != -1)
		path_h = ft_strjoin(&env[ft_get_id_var(env, "HOME")][5],
				"/.ft_minishell_history");
	id_usr = ft_get_id_var(env, "USER");
	ft_prompt2(env, ret, id_usr);
	ft_strnew(1);
	cmd = ft_gnlr(path_h, "", "", env);
	fd = open(path_h, O_WRONLY | O_APPEND);
	free(path_h);
	write(fd, cmd, ft_strlen(cmd));
	close(fd);
	ft_tcg(1);
	return (cmd);
}
