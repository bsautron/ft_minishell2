#include "ft_minishell.h"

void		ft_print_list_char(t_lstl *cmd)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_lstl_len(cmd) + 1));
	while (cmd)
	{
		tmp[i] = cmd->str[0];
		i++;
		cmd = cmd->next;
	}
	tmp[i] = '\0';
	ft_putstr(ft_reverse(tmp));
	free(tmp);
}
