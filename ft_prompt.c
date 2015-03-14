/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:36:20 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/26 06:17:01 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

typedef struct		s_key
{
	char	*tab_key[11];
	void	(*f[11])(t_env *, int *);

}					t_key;

char			*ft_prompt(t_env *env)
{
	char	buf[8];
	char	*the_cmd;
	t_lstl	*tmp;
	int		pos;
	int		fd;
	int		i;
	t_key	key;

	key.tab_key[0] = KEY_CTRL_D;
	key.tab_key[1] = KEY_UP;
	key.tab_key[2] = KEY_DOWN;
	key.tab_key[3] = KEY_RIGHT;
	key.tab_key[4] = KEY_LEFT;
	key.tab_key[5] = KEY_BACK_SPACE;
	key.tab_key[6] = KEY_DELETE;
	key.tab_key[7] = KEY_END;
	key.tab_key[8] = KEY_HOME;
	key.tab_key[9] = NULL;

	key.f[0] = ft_key_ctrl_d;
	key.f[1] = ft_key_up;
	key.f[2] = ft_key_down;
	key.f[3] = ft_key_right;
	key.f[4] = ft_key_left;
	key.f[5] = ft_key_back_space;
	key.f[6] = ft_key_delete;
	key.f[7] = ft_key_end;
	key.f[8] = ft_key_home;
	key.f[9] = NULL;

	ft_putstr("\033[33mDatPrompt>\033[0m ");
	ft_set_term(env);
	pos = 0;
	env->cmd = NULL;
	while (1)
	{
		ft_bzero(buf, 8);
		read(0, &buf, 7);
		if (buf[0] == '\n')
		{
			env->h_pos = 0;
			break ;
		}
		//dprintf(1, "[%x][%x][%x][%x][%x][%x][%x]\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6]);
		i = 0;
		while (key.tab_key[i])
		{
			if (ft_strequ(buf, key.tab_key[i]))
				break ;
			i++;
		}
		if (key.tab_key[i])
			(key.f[i])(env, &pos);
		else if (ft_isprint(buf[0]))
			ft_key_printable(env, buf, &pos);
	}
	the_cmd = ft_lstl_to_str(env->cmd);
	ft_lstl_free(&env->cmd);
	if (!ft_onlyesp(the_cmd))
	{
		if ((fd = open(env->path_h, O_WRONLY | O_APPEND)) != -1)
		{
			ft_putendl_fd(the_cmd, fd);
			close(fd);
		}
		ft_lstld_add(&env->history, the_cmd);
	}
	return (the_cmd);
}
