/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:38:10 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/07 18:23:59 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		size;
	int		i;
	char	*copy;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	i = -1;
	copy = (char*)malloc(sizeof(char) * size + 1);
	while (++i < size)
		copy[i] = f(i, s[i]);
	copy[i] = '\0';
	return (copy);
}
