/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:36:20 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/24 23:58:42 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"



void	ft_prompt(t_lstl *env)
{
	char	buf[4];
	t_lstl	*cmd;
	size_t	pos;

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
		if (buf[0] == '\033' && buf[2] == 'D')
		{
			if (pos < ft_lstl_len(cmd))
			{
				pos++;
				ft_make_instruction("le", NULL);
				ft_make_instruction("im", NULL);
			}
		}
		else if (buf[0] == '\033' && buf[2] == 'C')
		{
			if (pos != 0)
			{
				pos--;
				ft_make_instruction("nd", NULL);
			}
			if (pos == 0)
				ft_make_instruction("ei", NULL);
		}
		else if (buf[0] == 8 || buf[0] == 127)
		{
			if (pos < ft_lstl_len(cmd))
			{
				ft_make_instruction("le", NULL);
				ft_make_instruction("dc", NULL);
				ft_lstl_delone_by_id(&cmd, pos);
			}
		}
		//else if (buf[0] == '\033' && buf[2] == '3' && buf[3] == '~')

		else if (buf[0] != '\033')
		{
			ft_putchar(buf[0]);
			ft_lstl_insert(&cmd, buf, pos);
		}
	}
	ft_putendl("");
	ft_lstl_print(cmd);
	ft_putendl("");
}
