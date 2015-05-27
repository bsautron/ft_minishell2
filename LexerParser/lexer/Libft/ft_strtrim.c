/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:31:55 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/07 19:44:25 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*copy;
	int		size;
	int		s_start;
	int		s_end;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	s_start = 0;
	s_end = 0;
	while ((s[s_start] == ' '
		|| s[s_start] == '\t'
		|| s[s_start] == '\n') && s[s_start] != '\0')
		s_start++;
	if (s_start < size)
	{
		while (size != 0 && s_end < size
			&& (s[size - s_end - 1] == ' '
			|| s[size - s_end - 1] == '\n'
			|| s[size - s_end - 1] == '\t'))
			s_end++;
	}
	copy = ft_strsub(s, s_start, size - s_end - s_start);
	copy[size - s_end - s_start] = '\0';
	return (copy);
}
