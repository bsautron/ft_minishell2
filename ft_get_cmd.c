/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:36:20 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/23 19:29:08 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void ft_prompt2(void)
{
	char	*dirname;

	if (g_env.ret == 0)
	{
		dirname = ft_get_dirname();
		g_env.prompt = ft_strjoin(dirname, "> ");
		free(dirname);
	}
	/*else
	{
		ft_putstr("\x1b[31m");
		ft_putstr("\033[1;31;47m");
	}
	ft_putstr(g_env.prompt);
	ft_putstr("\033[0m\033[1D ");*/
}

static void		ft_init_t_key(t_key *key)
{
	key->tab_key[0] = KEY_CTRL_D;
	key->tab_key[1] = KEY_UP;
	key->tab_key[2] = KEY_DOWN;
	key->tab_key[3] = KEY_RIGHT;
	key->tab_key[4] = KEY_LEFT;
	key->tab_key[5] = KEY_BACK_SPACE;
	key->tab_key[6] = KEY_DELETE;
	key->tab_key[7] = KEY_END;
	key->tab_key[8] = KEY_HOME;
	key->tab_key[9] = KEY_ALT_RIGHT;
	key->tab_key[10] = KEY_ALT_LEFT;
	key->tab_key[11] = KEY_ALT_UP;
	key->tab_key[12] = KEY_ALT_DOWN;
	key->tab_key[13] = NULL;
	key->f[0] = ft_key_ctrl_d;
	key->f[1] = ft_key_up;
	key->f[2] = ft_key_down;
	key->f[3] = ft_key_right;
	key->f[4] = ft_key_left;
	key->f[5] = ft_key_back_space;
	key->f[6] = ft_key_delete;
	key->f[7] = ft_key_end;
	key->f[8] = ft_key_home;
	key->f[9] = ft_key_alt_right;
	key->f[10] = ft_key_alt_left;
	key->f[11] = ft_key_alt_up;
	key->f[12] = ft_key_alt_down;
	key->f[13] = NULL;
}

static void		ft_prompt(t_key key)
{
	char	buf[8];
	int		i;

	g_env.pos = 0;
	g_env.cmd = NULL;
	ft_set_term();
	while (1)
	{
		ft_bzero(buf, 8);
		read(0, &buf, 7);
		//dprintf(1, "key = \\%#x\\%#x\\%#x\\%#x\\%#x\\%#x\\%#x\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6]);
		if (buf[0] == '\n')
		{
			g_env.h_pos = 0;
			break ;
		}
		i = 0;
		while (key.tab_key[i])
		{
			if (ft_strequ(buf, key.tab_key[i]))
				break ;
			i++;
		}
		if (key.tab_key[i])
			(key.f[i])(&g_env.pos);
		else if (ft_isprint(buf[0]) && !buf[1])
			ft_key_printable(buf, &g_env.pos);
		else if (ft_isprint(buf[0]))
			ft_key_ctrl_v(buf, &g_env.pos);
	}
	//ft_lstl_free(&g_env.cmd);
}

static int	ft_check_scope(void)
{
	t_lstl		*tmp;
	int			scope_dquote;

	scope_dquote = 0;
	tmp = g_env.cmd_returned;
	while (tmp)
	{
		(g_env.scope_func[g_env.scope->id])(tmp->str[0]);
		tmp = tmp->next;
	}
	dprintf(1, "%s\n", "--");
	ft_scope_print(g_env.scope);
	return (0);
}

char	*ft_get_cmd(void)
{
	char	*the_cmd;
	int		fd;
	t_key	key;

	g_env.cmd_returned = NULL;
	ft_init_t_key(&key);
	ft_prompt2();
	ft_putstr(g_env.prompt);
	ft_prompt(key);
	while (ft_check_scope())
	{
		ft_putchar('\n');
		ft_putstr(g_env.prompt);
		ft_prompt(key);
	}
	the_cmd = ft_lstl_to_str(g_env.cmd_returned);
	ft_lstl_free(&g_env.cmd_returned);
	if (!ft_onlyesp(the_cmd))
	{
		if ((fd = open(g_env.path_h, O_WRONLY | O_APPEND)) != -1)
		{
			ft_putendl_fd(the_cmd, fd);
			close(fd);
		}
		ft_lstld_add(&g_env.history, the_cmd);
	}
	// A la fin il faut move le cursor a la fin de la commande pour ne pas empieter sur la suite
	return (the_cmd);
}
