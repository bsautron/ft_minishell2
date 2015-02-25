/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:36:20 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 02:06:46 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_prompt(t_lstl *env)
{
	char	buf[4];
	t_lstl	*cmd;
	size_t	pos;
	char	*the_cmd;
	int		i;

	ft_putstr("DatPrompt> ");
	cmd = NULL;
	ft_tcg(0);
	pos = 0;
	while (1)
	{
		ft_bzero(&buf, sizeof(char *));
		read(0, &buf, 4);
		if (buf[0] == '\n')
			break ;
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
		else if (buf[0] != '\033') // une lettre printable
		{
			ft_putchar(buf[0]);
			ft_lstl_insert(&cmd, buf, pos);
		}

	}
	the_cmd = (char *)malloc(sizeof(char) * (ft_lstl_len(cmd) + 1));
	i = 0;
	while (cmd)
	{
		the_cmd[i] = cmd->str[0];
		cmd = cmd->next;
		i++;
	}
	the_cmd[i] = '\0';
	ft_putstr("\ncmd = ");
	the_cmd = ft_reverse(the_cmd);
	ft_putendl(the_cmd);
}
