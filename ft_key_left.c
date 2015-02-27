#include "ft_minishell.h"

void		ft_key_left(t_env *env, int *pos)
{
	if (*pos < ft_lstl_len(env->cmd))
	{
		(*pos)++;
		ft_make_instruction("le", NULL);
		ft_make_instruction("im", NULL);
	}
}
