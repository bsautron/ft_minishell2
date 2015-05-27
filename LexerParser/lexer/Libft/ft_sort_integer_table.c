/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/07 03:01:06 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/07 13:54:47 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_tab_move_down(int *tab, int pos, int to)
{
	while (pos < to)
	{
		tab[pos] = tab[pos + 1];
		pos++;
	}
}

static void	ft_tab_move_up(int *tab, int pos, int to)
{
	while (pos > to)
	{
		tab[pos] = tab[pos - 1];
		pos--;
	}
}

static void	ft_tab_move_to(int *tab, int pos, int to)
{
	int nb;

	nb = tab[pos];
	if (pos > to)
	{
		ft_tab_move_up(tab, pos, to);
		tab[to] = nb;
	}
	else if (pos > to)
	{
		ft_tab_move_down(tab, pos, to);
		tab[to] = nb;
	}
}

static void	ft_get_integer_new_pos(int *tab, int size, int pos)
{
	int	i;
	int nb;

	nb = tab[pos];
	i = 0;
	while (i < size)
	{
		if (tab[i] >= nb)
		{
			ft_tab_move_to(tab, pos, i);
			break ;
		}
		i++;
	}
}

void		ft_sort_integer_table(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_get_integer_new_pos(tab, size, i);
		i++;
	}
}
