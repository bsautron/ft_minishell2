/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:06:49 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 11:26:49 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_parser(char *cmd, t_lstl *env)
{
	char	*var;
	size_t	i;
	size_t	j;
	char	*var_env;

	i = 0;
	while (cmd[i])
	{
		j = 0;
		if (cmd[i] == '\\')
			i++;
		else if (cmd[i] == '$')
		{
			while (cmd[i + j] && cmd[i + j] != ' ')
				j++;
			var = ft_strsub(cmd, i, j);
			if ((var_env = ft_get_env(ft_strjoin(var + 1, "="), env)) != NULL)
				cmd = ft_replace(cmd, var, var_env, i);
			else
				cmd = ft_replace(cmd, var, "", i);

		}
		i += 1 + j;
	}
	return (cmd);
}
