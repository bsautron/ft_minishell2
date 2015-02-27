#include "ft_minishell.h"

t_lstld	*ft_get_link_by_id(t_lstld *list, size_t id)
{
	size_t		i;

	i = 0;
	while (list && i++ < id)
		list = list->next;
	return (list);
}
