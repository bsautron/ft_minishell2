#include "ft_minishell.h"

void		ft_key_back_space(t_env *env, int *pos)
{
	if (*pos < ft_lstl_len(env->cmd))
	{
		ft_make_instruction("le", NULL);
		ft_make_instruction("dc", NULL);
		ft_lstl_delone_by_id(&env->cmd, *pos);
	}
}
