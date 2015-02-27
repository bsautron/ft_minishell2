#include "ft_minishell.h"

void		ft_key_up(t_env *env, int *pos)
{
	if (env->h_pos == 0)
		env->cmd_saved = env->cmd;
	if (env->h_pos < ft_lstld_len(env->history))
	{
		ft_key_home(env, pos);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr(ft_get_link_by_id(env->history, env->h_pos)->str);
		env->cmd = ft_str_to_lstl(ft_get_link_by_id(env->history, env->h_pos)->str);
		*pos = 0;
		env->h_pos++;
	}
}
