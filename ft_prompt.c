/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:36:20 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/01 02:18:42 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

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
	key->f[10] = NULL;
}

char			*ft_prompt(void)
{
	char	buf[8];
	char	*the_cmd;
	t_lstl	*tmp;
	int		fd;
	int		i;
	t_key	key;

	ft_putstr("\033[33mDatPrompt>\033[0m ");
	ft_init_t_key(&key);
	ft_set_term();
	g_env.pos = 0;
	g_env.cmd = NULL;
	while (1)
	{
		ft_bzero(buf, 8);
		read(0, &buf, 7);
//dprintf(1, "\\%#x\\%#x\\%#x\\%#x\\%#x\\%#x\\%#x\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6]);
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
		else if (ft_isprint(buf[0]))
			ft_key_printable(buf, &g_env.pos);
	}
	the_cmd = ft_lstl_to_str(g_env.cmd);
	ft_lstl_free(&g_env.cmd);
	if (!ft_onlyesp(the_cmd))
	{
		if ((fd = open(g_env.path_h, O_WRONLY | O_APPEND)) != -1)
		{
			ft_putendl_fd(the_cmd, fd);
			close(fd);
		}
		ft_lstld_add(&g_env.history, the_cmd);
	}
	return (the_cmd);
}

