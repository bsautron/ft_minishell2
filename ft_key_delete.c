#include "ft_minishell.h"

void		ft_key_delete(t_env *env, int *pos)
{
	ft_make_instruction("dc", NULL);
	if (*pos)
	{
		(*pos)--;
		ft_lstl_delone_by_id(&env->cmd, *pos);
	}
}
