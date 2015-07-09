/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 13:59:57 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/09 06:59:22 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static char	*ft_get_var(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (ft_strsub(str, 0, i));
}

void	ft_setenv(t_lstl **env, t_cmd *cmd)
{
	t_lstl	*tmp;
	char	*var;
	size_t	pos;
	int		i;

	i = 1;
	while (cmd->cmd[i])
	{
		tmp = *env;
		pos = 0;
		var = ft_strjoin(ft_get_var(cmd->cmd[i]), "=");
		while (tmp && !ft_strnequ(var, tmp->str, ft_strlen(var)))
		{
			pos++;
			tmp = tmp->next;
		}
		if (tmp)
		{	
			free(tmp->str);
			tmp->str = ft_strdup(cmd->cmd[i]);
		}
		else
			ft_lstl_add_back(env, cmd->cmd[i]);
		i++;
	}
}
