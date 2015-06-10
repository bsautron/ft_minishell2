#include <ft_sh.h>

char	**ft_lstl_to_tab(t_lstl *list)
{
	t_lstl	*tmp;
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
		tab[i] = ft_strdup(tmp->str);
		tmp = tmp->next;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
