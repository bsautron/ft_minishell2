#include <libft.h>

static int	ft_strlen_spec(char *str)
{
	int		i;

	i = 0;
	while (str[i] > ' ')
		i++;
	return (i);
}

static char	*ft_strdup_spec(char *str)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen_spec(str);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static int	nb_words(char *str)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] > ' ' && str[i + 1] <= ' ')
			nb++;
		i++;
	}
	return (nb);
}

char		**ft_strsplit_white_space(char *str)
{
	char	**tab;
	int		i;
	int		words;

	words = nb_words(str);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	i = 0;
	while (i < words)
	{
		while (*str && *str <= ' ')
			str++;
		tab[i] = ft_strdup_spec(str);
		str += ft_strlen_spec(str) + 1;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
