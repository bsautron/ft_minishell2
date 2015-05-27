/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 06:18:57 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/09 06:18:58 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_color(const char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(SHELL_WHITE_FG);
}
