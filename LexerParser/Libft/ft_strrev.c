/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/06 06:47:24 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/06 15:45:51 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		size;
	char	c;
	int		i;
	int		e;

	size = 0;
	while (str[size] != '\0')
		size++;
	i = 0;
	e = size;
	while (i < size / 2)
	{
		e--;
		c = str[i];
		str[i] = str[e];
		str[e] = c;
		i++;
	}
	return (str);
}
