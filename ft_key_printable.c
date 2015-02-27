#include "ft_minishell.h"

void		ft_key_printable(t_env *env, char *buf, int *pos)
{
	ft_putchar(buf[0]);
	env->h_pos = 0;
	ft_lstl_insert(&env->cmd, buf, *pos);
}
