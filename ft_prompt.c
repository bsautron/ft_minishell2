/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:36:20 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 15:26:58 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_prompt(t_env *env)
{
	char	buf[4];
	t_lstl	*cmd;
	t_lstl	*tmp;
	size_t	pos;
	char	*the_cmd;
	int		i;

	ft_putstr("\033[33mDatPrompt>\033[0m ");
	cmd = NULL;
	ft_tcg(env);
	pos = 0;
	while (1)
	{
		ft_bzero(&buf, sizeof(char *));
		read(0, &buf, 4);
		if (buf[0] == '\n')
			break ;
		if (buf[0] == 4 && buf[1] == 0)
		{
			if (ft_lstl_len(cmd) == 0)
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
					ft_lstl_delone_by_id(&cmd, pos);
				}
			}
		}
		if (buf[0] == '\033' && buf[2] == 'D') //gauche
		{
			if (pos < ft_lstl_len(cmd))
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
			if (pos < ft_lstl_len(cmd))
			{
				ft_make_instruction("le", NULL);
				ft_make_instruction("dc", NULL);
				ft_lstl_delone_by_id(&cmd, pos);
			}
		}
		else if (buf[0] == '\033' && buf[2] == '3' && buf[3] == '~') // touche delete
		{
			ft_make_instruction("dc", NULL);
			if (pos)
			{
				pos--;
				ft_lstl_delone_by_id(&cmd, pos);
			}
		}
		else if (buf[0] == '\033' && buf[1] == 91 && buf[2] == 70) // touche end
		{
			while (pos--)
				ft_make_instruction("nd", NULL);
			pos = 0;
		}
		else if (buf[0] == '\033' && buf[1] == 91 && buf[2] == 72) // touche Home
		{
			while (pos++ < ft_lstl_len(cmd))
				ft_make_instruction("le", NULL);
			pos = ft_lstl_len(cmd);
			ft_make_instruction("im", NULL);
		}
		else if (ft_isprint(buf[0]) && buf[1] == 0 && buf[2] == 0 && buf[4] == 0) // une lettre printable
		{
			ft_putchar(buf[0]);
			ft_lstl_insert(&cmd, buf, pos);
		}
	}
	the_cmd = (char *)malloc(sizeof(char) * (ft_lstl_len(cmd) + 1));
	i = 0;
	tmp = cmd;
	while (tmp)
	{
		the_cmd[i] = tmp->str[0];
		tmp = tmp->next;
		i++;
	}
	ft_lstl_free(&cmd);
	the_cmd[i] = '\0';
	the_cmd = ft_reverse(the_cmd);
	ft_lstld_add(&env->history, the_cmd);
	return (the_cmd);
}
