/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:03:15 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 13:11:54 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_replace(char *src, char *str1, char *str2, int pos)
{
	char	*str;
	char	*begin;
	int		i;
	int		len;
	int		final_len;

	i = 0;
	final_len = ft_strlen(src) - (ft_strlen(str1) - ft_strlen(str2));
	str = (char *)malloc(sizeof(char) * (final_len + 1));
	if (!str || !ft_strstr(src, str1))
		return (NULL);
	str = ft_strcpy(str, src);
	begin = ft_strstr(str + pos, str1);
	while (str2[i])
	{
		begin[i] = str2[i];
		i++;
	}
	len = begin - str + ft_strlen(str1);
	while (src[len])
		begin[i++] = src[len++];
	str[final_len] = '\0';
	return (str);
}
