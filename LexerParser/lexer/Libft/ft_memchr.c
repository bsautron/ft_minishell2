/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:39:14 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/03 14:31:01 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;

	if (s == NULL || n == 0)
		return (NULL);
	i = -1;
	ss = (unsigned char*)s;
	while (++i < n)
		if (*(ss + i) == (unsigned char)c)
			return (ss + i);
	return (NULL);
}
