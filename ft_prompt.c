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



char			*ft_prompt(t_env *env)
{
	char	buf[8];
	char	*the_cmd;
	t_lstl	*tmp;
	int		pos;
	int		fd;
	int		i;

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
		if (ft_strequ(buf, KEY_CTRL_D))
			ft_ctrl_d(env, &pos);
		else if (ft_strequ(buf, KEY_UP))
			ft_key_up(env, &pos);
		else if (ft_strequ(buf, KEY_DOWN))
			ft_key_down(env, &pos);
		else if (ft_strequ(buf, KEY_LEFT))
			ft_key_left(env, &pos);
		else if (ft_strequ(buf, KEY_RIGHT))
			ft_key_right(env, &pos);
		else if (ft_strequ(buf, KEY_BACK_SPACE))
			ft_key_back_space(env, &pos);
		else if (ft_strequ(buf, KEY_DELETE)) // touche delete
			ft_key_delete(env, &pos);
		else if (ft_strequ(buf, KEY_END)) // touche end
			ft_key_end(env, &pos);
		else if (ft_strequ(buf, KEY_HOME)) // touche Home
			ft_key_home(env, &pos);
		else if (ft_isprint(buf[0])) // une lettre printable
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
