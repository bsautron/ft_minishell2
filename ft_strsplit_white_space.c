/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:35:29 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/27 22:38:13 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int		nb_words(char const *s)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] > ' ' && s[i + 1] <= ' ')
			len++;
		else if (s[i] > ' ' && !s[i + 1])
			len++;
		i++;
	}
	return (len);
}

static int		len_split(char const *s)
{
	int		len;

	len = 0;
	while (s[len] && s[len] > ' ')
		len++;
	return (len);
}

static char		*cpy_split(char *dst, char const *src)
{
	int		i;

	i = 0;
	while (src[i] > ' ')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			**ft_strsplit_white_space(char const *s)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	tab = NULL;
	if (s)
	{
		words = nb_words(s);
		tab = (char **)malloc(sizeof(char *) * (words + 1));
		while (i < words)
		{
			while (*s <= ' ')
				s++;
			tab[i] = (char *)malloc(sizeof(char) * (len_split(s) + 1));
			cpy_split(tab[i], s);
			s += len_split(s);
			i++;
		}
		tab[i] = NULL;
	}
	return (tab);
}
