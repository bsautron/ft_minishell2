#include "libl.h"

void	ft_lstl_add_back(t_lstl **begin, char *str)
{
	t_lstl	*new;
	t_lstl	*tmp;

	new = ft_lstl_create(str);
	if (!(*begin))
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
