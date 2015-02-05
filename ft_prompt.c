/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 02:25:46 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/05 15:10:27 by bsautron         ###   ########.fr       */
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
	ft_putstr(cmd);
	return (cmd);
}

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

static char	*ft_gnlr(char *path_h, char *cmd, char *cmd_saved)
{
	int			nb;
	char		c[2];
	char		cac;
	int			i;
	char		**history;
	int			pos;

	nb = 0;
	i = 0;
	pos = 0;
	history = ft_make_history(&nb, &i, path_h);
	while (read(0, &cac, 1) != 0 && cac != '\n')
	{
		if (cac == '\033')
		{
			read(0, c, 1);
			read(0, c, 1);
			if (*c == 'A' || *c == 'B')
			{
				ft_increm(&i, nb, *c);
				ft_nclear(ft_strlen(cmd));
				cmd = ft_increm2(*c, history, cmd_saved, cmd, &i, nb);
			}
			else if (*c == 'D' || *c == 'C')
				ft_mouv_lr(*c, &pos);
		}
		else
		{
			cmd = ft_join_or_del(cmd, c, cac, &pos);
			cmd_saved = ft_strdup(cmd);
		}
		ft_nclear(ft_strlen(cmd) - 1);
		ft_putstr(cmd);
		i = 0;
		while (i < (int)ft_strlen(cmd) - pos)
		{
			ft_putstr("\033[1D");
			i++;
		}
	}
	i = 0;
	while (history[i])
	{
		free(history[i]);
		i++;
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

	if (env && ft_get_id_var(env, "HOME") != -1)
		path_h = ft_strjoin(&env[ft_get_id_var(env, "HOME")][5],
				"/.ft_minishell_history");
	id_usr = ft_get_id_var(env, "USER");
	ft_putstr("\033[2K\r");
	ft_prompt2(env, ret, id_usr);
	cmd = ft_gnlr(path_h, "", "");
	ft_putchar('\n');
	fd = open(path_h, O_WRONLY | O_APPEND);
	free(path_h);
	write(fd, cmd, ft_strlen(cmd));
	write(fd, "\n", 1);
	close(fd);
	return (cmd);
}
