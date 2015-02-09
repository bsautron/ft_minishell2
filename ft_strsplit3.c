/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:35:29 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/09 06:05:14 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int		nb_words(char const *s, char *c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (ft_strnequ(&s[i], c, ft_strlen(c)))
		{
			len++;
		}
		i++;
	}
	return (len + 1);
}

static int		len_split(char const *s, char *c)
{
	int		len;

	len = 0;
	while (s[len] && !ft_strnequ(&s[len], c, ft_strlen(c)))
		len++;
	return (len);
}

static char		*cpy_split(char *dst, char const *src, char *c)
{
	int		i;

	i = 0;
	if (src)
	{
		while (src[i] && !ft_strnequ(&src[i], c, ft_strlen(c)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

char			**ft_strsplit_str(char const *s, char *c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	tab = NULL;
	if (s)
	{
		words = nb_words(s, c);
		tab = (char **)malloc(sizeof(char *) * (words + 1));
		while (i < words)
		{
			while (s && ft_strnequ(s, c, ft_strlen(c)))
				s++;
			tab[i] = (char *)malloc(sizeof(char) * (len_split(s, c) + 1));
			cpy_split(tab[i], s, c);
			s += len_split(s, c) + ft_strlen(c);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
