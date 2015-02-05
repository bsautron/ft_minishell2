/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 09:01:12 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/04 22:24:04 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h" 

char ft_first_redir(char *cmd)
{
	int     i;

	i = 0;
	while (cmd && cmd[i])
	{
		if (cmd[i] == '|')
			return ('|');
		if (cmd[i] == '>' && cmd[i + 1] == '>')
			return ('.');
		if (cmd[i] == '<' && cmd[i + 1] == '<')
			return (',');
		if (cmd[i] == '>')
			return ('>');
		if (cmd[i] == '<')
			return ('<');
		i++;
	}
	return (0);
}
