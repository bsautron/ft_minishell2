#include "ft_minishell.h"

t_lstl	*ft_str_to_lstl(char *str)
{
	t_lstl	*ret;
	char	b[2];
	int		i;

	ret = NULL;
	b[1] = 0;
	i = 0;
	while (str[i])
	{
		b[0] = str[i];
		ft_lstl_add(&ret, b);
		i++;
	}
	return (ret);
}
