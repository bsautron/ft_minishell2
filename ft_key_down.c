#include "ft_minishell.h"

void		ft_key_down(t_env *env, int *pos)
{
	env->h_pos--;
	if (env->h_pos > 0)
	{
		ft_key_home(env, pos);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr(ft_get_link_by_id(env->history, env->h_pos - 1)->str);
		env->cmd = ft_str_to_lstl(
				ft_get_link_by_id(env->history, env->h_pos - 1)->str);
		*pos = 0;
	}
	else if (env->h_pos == 0)
	{
		ft_key_home(env, pos);
		env->cmd = env->cmd_saved;
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_print_list_char(env->cmd);
		*pos = 0;
	}
	else
		env->h_pos = 0;
}
