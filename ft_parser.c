/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:06:49 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 12:33:39 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static char	*get_name_var(char *str)
{
	size_t	i;

	i = 1;
	while (str[i] && ft_isalnum(str[i]))
		i++;
	return (ft_strsub(str, 0, i));
}

char	*ft_parser(char *cmd, t_lstl *env)
{
	char	*var;
	char	*var_eq;
	size_t	i;
	char	*var_env;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$')
		{
			if (i == 0 || (i != 0 && cmd[i - 1] != '\\'))
			{
				var = get_name_var(&cmd[i]);
				if ((var_env = ft_get_env(ft_strjoin(var + 1, "="), env)) == NULL)
					var_env = "";
				cmd = ft_replace(cmd, var, var_env, (i == 0) ? 0 : i - 1);
			}
		}
		i += 1;
	}
	return (cmd);
}
