#include <ft_sh.h>

char	**ft_tk_to_tab(t_token *list)
{
	t_token	*tmp;
	int		i;
	char	**tab;

	tmp = list;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	tmp = list;
	i = 0;
	while (tmp)
	{
		tab[i] = ft_strdup(tmp->value);
		tmp = tmp->next;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
