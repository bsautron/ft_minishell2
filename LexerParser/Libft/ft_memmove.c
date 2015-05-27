/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:59:06 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/07 17:33:48 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *s1, const void *s2, size_t len)
{
	void		*cpy;

	cpy = malloc(len);
	ft_memcpy(cpy, s2, len);
	ft_memcpy(s1, cpy, len);
	free(cpy);
	return (s1);
}
