/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 00:23:38 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/09 00:31:16 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_path_join(char *s1, char *s2)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	i = 0;
	while (s1[i] && s1[i + 1])
		i++;
	if (s1[i] == '/' && *s2 == '/')
		return (ft_strjoin(s1, s2 + 1));
	else if (s1[i] != '/' && *s2 != '/')
	{
		tmp1 = ft_strjoin(s1, "/");
		tmp2 = ft_strjoin(tmp1, s2);
		free(tmp1);
		return (tmp2);
	}
	return (ft_strjoin(s1, s2));
}
