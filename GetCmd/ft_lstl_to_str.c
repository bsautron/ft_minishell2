#include "ft_minishell.h"

char		*ft_lstl_to_str(t_lstl *list)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (ft_lstl_len(list) + 1));
	while (list)
	{
		dst[i] = list->str[0];
		list = list->next;
		i++;
	}
	dst[i] = '\0';
	dst = ft_reverse(dst);
	return (dst);
}
