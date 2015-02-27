#include "ft_minishell.h"

void		ft_key_home(t_env *env, int *pos)
{
	while ((*pos)++ < ft_lstl_len(env->cmd))
		ft_make_instruction("le", NULL);
	*pos = ft_lstl_len(env->cmd);
	ft_make_instruction("im", NULL);
}
