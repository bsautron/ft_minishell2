/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:01:28 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/06 15:45:01 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;

	copy = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!copy)
		return (NULL);
	ft_strcpy(copy, str);
	return (copy);
}
