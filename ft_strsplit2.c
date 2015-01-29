/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:55:55 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/28 13:37:17 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

#define FUCK len = 0; i = 0; inside = 0

static int			nb_word(char const *str)
{
	int				i;
	int				len;
	int				inside;

	i = 0;
	len = 0;
	inside = 0;
	while (str[i])
	{
		if (str[i] == '\"' && inside == 0)
			inside = 1;
		else if (str[i] == '\"' && inside == 1)
			inside = 0;
		if (str[i] > ' ' && str[i + 1] <= ' ' && inside == 0)
			len++;
		else if (str[i] > ' ' && !str[i + 1] && inside == 0)
			len++;
		i++;
	}
	return (len);
}

static int			lensplit(char const *str)
{
	int				len;
	int				inside;
	int				i;

	FUCK;
	while (str[len])
	{
		if (str[i] == '\"' && inside == 0)
		{
			inside = 1;
			len++;
		}
		else if (str[i] == '\"' && inside == 1)
		{
			inside = 0;
			len++;
		}
		if (inside == 0 && str[i] && str[i] > ' ')
			len++;
		if (str[i] <= ' ' && inside == 0)
			return (i);
		i++;
	}
	return (len);
}

static char			*cpy_split(char *dst, char const *src)
{
	int				i;
	int				inside;

	i = 0;
	inside = 0;
	while (src[i] && (src[i] > ' ' || inside == 1))
	{
		if (src[i] == '\"' && inside == 0)
			inside = 1;
		else if (src[i] == '\"' && inside == 1)
			inside = 0;
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char				*ft_strtrim2(char const *s)
{
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (s[i] == '\"')
		i++;
	while (s[len] == '\"')
		len--;
	return (ft_strsub(s, i, len - i + 1));
}

char				**ft_strsplit_whitespace(char const *s)
{
	char			**tab;
	int				words;
	int				i;

	i = 0;
	if (s)
	{
		words = nb_word(s);
		tab = (char **)malloc(sizeof(char *) * (words + 2));
		while (i < words)
		{
			while (*s && *s <= ' ')
				s++;
			tab[i] = (char *)malloc(sizeof(char) * (lensplit(s) + 1));
			tab[i] = cpy_split(tab[i], s);
			tab[i] = ft_strtrim2(tab[i]);
			s += lensplit(s);
			i++;
		}
		tab[i] = NULL;
		tab[i + 1] = NULL;
	}
	return (tab);
}
