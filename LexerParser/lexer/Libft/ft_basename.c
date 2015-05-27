/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 17:52:48 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/30 18:00:13 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_basename(char *path)
{
	char		*base;

	base = ft_strrchr(path, '/');
	return (base ? base + 1 : path);
}
