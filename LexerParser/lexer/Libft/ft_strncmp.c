/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:37:19 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/03 14:33:16 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	if ((s1 == NULL && s2 == NULL)
		|| (s1 == NULL && *s2 == 0)
		|| (*s1 == 0 && s2 == NULL))
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && (i + 1) < n)
		i++;
	return ((n == 0) ? 0 : (unsigned char)s1[i] - (unsigned char)s2[i]);
}
