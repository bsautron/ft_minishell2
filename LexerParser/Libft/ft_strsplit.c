/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 23:36:14 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/10 02:00:18 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int		ft_strlen_word(char *s, char c)
{
	int			i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int		ft_cwords(char *s, char c)
{
	int			i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static char		*ft_copy_word(char *s, char c)
{
	char		*word;
	int			i;

	printf("INSIDE COPY WORD:\n");
	printf("    COPYING: %s$\n", s);
	word = (char*)malloc(sizeof(char) * (ft_strlen_word(s, c) + 1));
	i = -1;
	while (s[++i] && s[i] != c)
		word[i] = s[i];
	word[i] = '\0';
	printf("    AFTER COPYING: %s\n", s);
	printf("    COPIED: %s$\n", word);
	return (word);
}

char			**ft_strsplit(char *s, char c)
{
	char		**tab;
	int			word;

	ft_putendl("hehe");
	if ((tab = (char**)malloc(sizeof(char*) * (ft_cwords(s, c) + 1))) == NULL)
		return (NULL);
	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		tab[word] = ft_copy_word(s, c);
		dprintf(1, "AFTER WORD IN TAB: %s\n", s);
		while (*s && *s != c)
			s++;
		printf("BIG AFTER COPYING: %s\n", s);
		word++;
	}
	tab[word] = NULL;
	return (tab);
}
