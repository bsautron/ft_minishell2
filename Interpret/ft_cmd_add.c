#include <interpret.h>

void    ft_cmd_add(t_cmd **begin, char *str)
{
	t_cmd  *new;

	new = ft_lstl_create(str);
	if (!(*begin))
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
}
