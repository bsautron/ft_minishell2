#include "ft_minishell.h"

void		ft_ctrl_d(t_env *env, int *pos)
{
	if (ft_lstl_len(env->cmd) == 0)
	{
		ft_reset_term();
		exit(0);
	}
	else
	{
		ft_make_instruction("dc", NULL);
		if (*pos)
		{
			(*pos)--;
			ft_lstl_delone_by_id(&env->cmd, *pos);
		}
	}
}
