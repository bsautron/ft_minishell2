/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:48:35 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/07 19:19:30 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*nb;
	int		len;
	int		sign;

	len = 0;
	sign = 0;
	if (n < 0)
	{
		len = 1;
		sign = 1;
	}
	len += ft_intlen(n);
	nb = (char*)malloc(sizeof(char) * len + 1);
	if (sign == 1)
		nb[0] = '-';
	nb[len] = '\0';
	while (len-- > sign)
	{
		if (n < 0)
			nb[len] = n % 10 * -1 + 48;
		else
			nb[len] = n % 10 + 48;
		n = n / 10;
	}
	return (nb);
}
