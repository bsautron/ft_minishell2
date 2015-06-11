#include <libl.h>

t_lstl	*ft_lstl_clone(t_lstl *list)
{
	t_lstl	*dest;

	dest = NULL;
	while (list)
	{
		ft_lstl_add_back(&dest, list->str);
		list = list->next;
	}
	return (dest);
}
