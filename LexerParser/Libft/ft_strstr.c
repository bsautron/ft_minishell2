/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:52:36 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/08 14:30:11 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		size;

	i = -1;
	size = ft_strlen(s2);
	if (size == 0)
		return ((char*)s1);
	while (s1[++i] != '\0')
		if (s1[i] == s2[0])
			if (ft_strncmp(s1 + i, s2, size) == 0)
				return ((char*)s1 + i);
	return (NULL);
}
