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

static t_lstl	*ft_str_to_lstl(char *str)
{
	t_lstl	*ret;
	char	b[2];
	int		i;

	ret = NULL;
	b[1] = 0;
	i = 0;
	while (str[i])
	{
		b[0] = str[i];
		ft_lstl_add(&ret, b);
		i++;
	}
	return (ret);
}

static char		*ft_lstl_to_str(t_lstl *list)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (ft_lstl_len(list) + 1));
	while (list)
	{
		dst[i] = list->str[0];
		list = list->next;
		i++;
	}
	dst[i] = '\0';
	dst = ft_reverse(dst);
	return (dst);
}

static t_lstld	*ft_get_link_by_id(t_lstld *list, size_t id)
{
	size_t		i;

	i = 0;
	while (list && i++ < id)
		list = list->next;
	return (list);
}

static void		ft_print_list_char(t_lstl *cmd)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_lstl_len(cmd) + 1));
	while (cmd)
	{
		tmp[i] = cmd->str[0];
		i++;
		cmd = cmd->next;
	}
	tmp[i] = '\0';
	ft_putstr(ft_reverse(tmp));
	free(tmp);
}

static void		ft_key_home(t_env *env, int *pos)
{
	while ((*pos)++ < ft_lstl_len(env->cmd))
		ft_make_instruction("le", NULL);
	*pos = ft_lstl_len(env->cmd);
	ft_make_instruction("im", NULL);
}

static void		ft_key_up(t_env *env, int *pos)
{
	if (env->h_pos == 0)
		env->cmd_saved = env->cmd;
	if (env->h_pos < ft_lstld_len(env->history))
	{
		ft_key_home(env, pos);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr(ft_get_link_by_id(env->history, env->h_pos)->str);
		env->cmd = ft_str_to_lstl(ft_get_link_by_id(env->history, env->h_pos)->str);
		*pos = 0;
		env->h_pos++;
	}
}

static void		ft_key_down(t_env *env, int *pos)
{
	env->h_pos--;
	if (env->h_pos > 0)
	{
		ft_key_home(env, pos);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr(ft_get_link_by_id(env->history, env->h_pos - 1)->str);
		env->cmd = ft_str_to_lstl(ft_get_link_by_id(env->history, env->h_pos - 1)->str);
		*pos = 0;
	}
	else if (env->h_pos == 0)
	{
		ft_key_home(env, pos);
		env->cmd = env->cmd_saved;
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_print_list_char(env->cmd);
		*pos = 0;
	}
	else
		env->h_pos = 0;
}

static void		ft_key_left(t_env *env, int *pos)
{
	if (*pos < ft_lstl_len(env->cmd))
	{
		(*pos)++;
		ft_make_instruction("le", NULL);
		ft_make_instruction("im", NULL);
	}
}

static void		ft_key_right(t_env *env, int *pos)
{
	env = env;
	if (*pos != 0)
	{
		(*pos)--;
		ft_make_instruction("nd", NULL);
	}
	if (*pos == 0)
		ft_make_instruction("ei", NULL);
}

static void		ft_key_back_space(t_env *env, int *pos)
{
	if (*pos < ft_lstl_len(env->cmd))
	{
		ft_make_instruction("le", NULL);
		ft_make_instruction("dc", NULL);
		ft_lstl_delone_by_id(&env->cmd, *pos);
	}
}

static void		ft_key_delete(t_env *env, int *pos)
{
	ft_make_instruction("dc", NULL);
	if (*pos)
	{
		(*pos)--;
		ft_lstl_delone_by_id(&env->cmd, *pos);
	}
}

static void		ft_key_end(t_env *env, int *pos)
{
	env = env;
	while ((*pos)--)
		ft_make_instruction("nd", NULL);
	*pos = 0;
}

static void		ft_key_printable(t_env *env, char *buf, int *pos)
{
	ft_putchar(buf[0]);
	env->h_pos = 0;
	ft_lstl_insert(&env->cmd, buf, *pos);
}

char			*ft_prompt(t_env *env)
{
	char	buf[4];
	char	*the_cmd;
	t_lstl	*tmp;
	int		pos;
	int		fd;
	int		i;

	ft_putstr("\033[33mDatPrompt>\033[0m ");
	ft_tcg(env);
	pos = 0;
	env->cmd = NULL;
	while (1)
	{
		ft_bzero(buf, 4);
		read(0, &buf, 4);
		if (buf[0] == '\n')
		{
			env->h_pos = 0;
			break ;
		}
		if (buf[0] == 4 && buf[1] == 0) // delete
			ft_ctrl_d(env, &pos);
		else if (buf[0] == '\033' && buf[2] == 'A') //haut
			ft_key_up(env, &pos);
		else if (buf[0] == '\033' && buf[2] == 'B') // bas
			ft_key_down(env, &pos);
		else if (buf[0] == '\033' && buf[2] == 'D') //gauche
			ft_key_left(env, &pos);
		else if (buf[0] == '\033' && buf[2] == 'C') //droite
			ft_key_right(env, &pos);
		else if (buf[0] == 8 || buf[0] == 127) //touche effacer
			ft_key_back_space(env, &pos);
		else if (buf[0] == '\033' && buf[2] == '3' && buf[3] == '~') // touche delete
			ft_key_delete(env, &pos);
		else if (buf[0] == '\033' && buf[1] == 91 && buf[2] == 70) // touche end
			ft_key_end(env, &pos);
		else if (buf[0] == '\033' && buf[1] == 91 && buf[2] == 72) // touche Home
			ft_key_home(env, &pos);
		else if (ft_isprint(buf[0]) && buf[1] == 0 && buf[2] == 0 && buf[3] == 0) // une lettre printable
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
