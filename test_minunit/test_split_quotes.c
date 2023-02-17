
#include "minunit.h"


static int	ft_strlen_pp(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	count_space_quotes(char **s, char q)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(s[i])
	{
		if (s[i][0] != q)
			j += count_words(s[i], ' ');
		else if (s[i][0] == q)
			j++;
		i++;
	}
	return (j);
}

static void	dvd_by_space(char **s, char **tmp, int *i, int *k)
{
	char	**tmp2;
	int		j;

	tmp2 = NULL;
	j = 0;
	tmp2 = ft_split(s[*i], ' ');
	while (tmp2[j])
	{
		tmp[*k] = ft_substr(tmp2[j], 0, ft_strlen(tmp2[j]));
		j++;
		(*k)++;
	}
	(*i)++;
}

static char	**core_space_quotes(char **s, char **tmp, char q)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while(s[i])
	{
		if (s[i][0] != q)
			dvd_by_space(s, tmp, &i, &k);
		else
		{
			tmp[k] = ft_substr(s[i], 0, ft_strlen(s[i]));
			k++;
			i++;
		}
	}
	tmp[k] = NULL;
	return(tmp);
}

static char	**ssplit_space_quotes(char **s, char q)
{
	char	**tmp;
	int		qt_mem_allocate;

	tmp = NULL;
	qt_mem_allocate = count_space_quotes(s, q);
	tmp = malloc((qt_mem_allocate + 1) * sizeof(char *));
	tmp = core_space_quotes(s, tmp, q);
	return (tmp);
}


// # Arrage
char	*test_split_quotes(void)
{
	char 	*teste = "um \'teste maluco\' lalaal | > >> << cat \'teste\'";
	char 	**quotes;
	char 	**fin_quotes;
	int		i;
	int		j;
	int		k;
	
	i = 0;
	j = 0;
	k = 0;
	quotes = NULL;
	fin_quotes = NULL;
	quotes = split_quotes(teste, '\'');
	printf("string: %s\n\n", teste);
	while (quotes[i])
		printf("posição [%i] ->%s\n\n", j++, quotes[i++]);
	printf("----------------------\n");
	i = 0;
	j = 0;
	fin_quotes = ssplit_space_quotes(quotes, '\'');
	while (fin_quotes[i])
		printf("posição [%i] ->%s\n\n", j++, fin_quotes[i++]);
	k = ft_strlen_pp(quotes);
	// printf("qtd: %i\n\n", k);

	// // # Assert
	// mu_assert("ERROR: test_split_quotes", !strcmp(teste, quotes[1]));
	return (0);
}
