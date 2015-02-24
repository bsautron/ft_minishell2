#include "libl.h"

t_lstl	*ft_lstl_create(char *str)
{
	t_lstl	*new;

	new = (t_lstl *)malloc(sizeof(t_lstl));
	new->str = ft_strdup(str);
	new->next = NULL;
	return (new);
}
