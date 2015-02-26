/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:36:20 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/26 03:51:09 by bsautron         ###   ########.fr       */
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

static t_lstld	*ft_get_link_by_id(t_lstld *list, size_t id)
{
	size_t		i;

	i = 0;
	while (list && i++ < id)
		list = list->next;
	return (list);
}

static void		ft_home(t_env *env, size_t *pos)
{
	while ((*pos)++ < ft_lstl_len(env->cmd))
		ft_make_instruction("le", NULL);
	*pos = ft_lstl_len(env->cmd);
	ft_make_instruction("im", NULL);
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
}

char			*ft_prompt(t_env *env)
{
	char	buf[4];
	char	*the_cmd;
	t_lstl	*tmp;
	size_t	pos;
	int		i;

	ft_putstr("\033[33mDatPrompt>\033[0m ");
	ft_tcg(env);
	pos = 0;
	env->cmd = NULL;
	while (1)
	{
		ft_bzero(&buf, sizeof(char *));
		read(0, &buf, 4);
		if (buf[0] == '\n')
		{
			env->h_pos = 0;
			break ;
		}
		if (buf[0] == 4 && buf[1] == 0) // delete
		{
			if (ft_lstl_len(env->cmd) == 0)
			{
				ft_reset_term();
				exit(0);
			}
			else
			{
				ft_make_instruction("dc", NULL);
				if (pos)
				{
					pos--;
					ft_lstl_delone_by_id(&env->cmd, pos);
				}
			}
		}
		else if (buf[0] == '\033' && buf[2] == 'A') //haut
		{
			if (env->h_pos == 0)
			{
				env->cmd_saved = env->cmd;
			}
			if (env->h_pos < ft_lstld_len(env->history))
			{
				ft_home(env, &pos);
				ft_make_instruction("ei", NULL);
				ft_make_instruction("cd", NULL);
				ft_putstr(ft_get_link_by_id(env->history, env->h_pos)->str);
				env->cmd = ft_str_to_lstl(ft_get_link_by_id(env->history, env->h_pos)->str);
				pos = 0;
				env->h_pos++;
			}
		}
		else if (buf[0] == '\033' && buf[2] == 'B') // bas
		{
			if (env->h_pos > 1)
			{
				env->h_pos--;
				ft_home(env, &pos);
				ft_make_instruction("ei", NULL);
				ft_make_instruction("cd", NULL);
				ft_putstr(ft_get_link_by_id(env->history, env->h_pos - 1)->str);
				env->cmd = ft_str_to_lstl(ft_get_link_by_id(env->history, env->h_pos - 1)->str);
				pos = 0;
			}
			else
			{
				env->h_pos = 0;
				ft_home(env, &pos);
				env->cmd = env->cmd_saved;
				ft_make_instruction("ei", NULL);
				ft_make_instruction("cd", NULL);
				ft_print_list_char(env->cmd);
				pos = 0;
			}
		}
		else if (buf[0] == '\033' && buf[2] == 'D') //gauche
		{
			if (pos < ft_lstl_len(env->cmd))
			{
				pos++;
				ft_make_instruction("le", NULL);
				ft_make_instruction("im", NULL);
			}
		}
		else if (buf[0] == '\033' && buf[2] == 'C') //droite
		{
			if (pos != 0)
			{
				pos--;
				ft_make_instruction("nd", NULL);
			}
			if (pos == 0)
				ft_make_instruction("ei", NULL);
		}
		else if (buf[0] == 8 || buf[0] == 127) //touche effacer
		{
			if (pos < ft_lstl_len(env->cmd))
			{
				ft_make_instruction("le", NULL);
				ft_make_instruction("dc", NULL);
				ft_lstl_delone_by_id(&env->cmd, pos);
			}
		}
		else if (buf[0] == '\033' && buf[2] == '3' && buf[3] == '~') // touche delete
		{
			ft_make_instruction("dc", NULL);
			if (pos)
			{
				pos--;
				ft_lstl_delone_by_id(&env->cmd, pos);
			}
		}
		else if (buf[0] == '\033' && buf[1] == 91 && buf[2] == 70) // touche end
		{
			while (pos--)
				ft_make_instruction("nd", NULL);
			pos = 0;
		}
		else if (buf[0] == '\033' && buf[1] == 91 && buf[2] == 72) // touche Home
			ft_home(env, &pos);
		else if (ft_isprint(buf[0]) && buf[1] == 0 && buf[2] == 0 && buf[4] == 0) // une lettre printable
		{
			ft_putchar(buf[0]);
			env->h_pos = 0;
			ft_lstl_insert(&env->cmd, buf, pos);
		}
	}
	the_cmd = (char *)malloc(sizeof(char) * (ft_lstl_len(env->cmd) + 1));
	i = 0;
	tmp = env->cmd;
	while (tmp)
	{
		the_cmd[i] = tmp->str[0];
		tmp = tmp->next;
		i++;
	}
	ft_lstl_free(&env->cmd);
	the_cmd[i] = '\0';
	the_cmd = ft_reverse(the_cmd);
	if (!ft_onlyesp(the_cmd))
		ft_lstld_add(&env->history, the_cmd);
	return (the_cmd);
}
