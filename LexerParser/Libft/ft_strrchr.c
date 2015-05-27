/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:59:19 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/07 16:50:47 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		size;

	size = ft_strlen(str);
	while (size >= 0)
	{
		if (str[size] == c)
			return ((char*)str + size);
		size--;
	}
	return (NULL);
}
