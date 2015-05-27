/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:08:04 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/07 13:48:53 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srce;

	dest = (unsigned char*)dst;
	srce = (unsigned char*)src;
	i = -1;
	while (++i < n)
	{
		*(dest + i) = *(srce + i);
		if (*(srce + i) == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
