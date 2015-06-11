/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 13:59:57 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/29 14:25:45 by bsautron         ###   ########.fr       */
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

void	ft_setenv(t_lstl **env, char *str)
{
	char	**tab;
	t_lstl	*tmp;
	char	*var;
	size_t	pos;
	int		i;

	tab = ft_strsplit_white_space(str);
	// cest pas un split_white_space quil faut faire
	i = 0;
	while (tab[i])
	{
		tmp = *env;
		pos = 0;
		var = ft_strjoin(ft_get_var(tab[i]), "=");
		while (tmp && !ft_strnequ(var, tmp->str, ft_strlen(var)))
		{
			pos++;
			tmp = tmp->next;
		}
		if (tmp)
		{	
			free(tmp->str);
			tmp->str = ft_strdup(tab[i]);
		}
		else
			ft_lstl_add_back(env, tab[i]);
		i++;
	}
}
