/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 05:51:18 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/29 12:27:58 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_pwd(void)
{
	char	dir[1024];

	if (getcwd(dir, sizeof(dir)) != NULL)
		return (ft_strdup(dir));
	return (NULL);
}
