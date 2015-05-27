/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:40:20 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/08 14:28:43 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = -1;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[++i] != '\0' && n > 0)
	{
		if (s1[i] == s2[0])
		{
			j = 1;
			while (s2[j] != '\0' && n - j > 0 && s1[i + j] == s2[j])
				j++;
			if (s2[j] == '\0')
				return ((char*)s1 + i);
		}
		n--;
	}
	return (NULL);
}
