
#include "minunit.h"


static int	ft_strlen_pp(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	**ssplit_space_quotes(char **s, char q)
{
	char	**tmp;
	char	**tmp2;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	tmp = NULL;
	tmp2 = NULL;
	while(s[i])
	{
		if (s[i][0] != q)
			j += count_words(s[i], ' ');
		else if (s[i][0] == q)
			j++;
		i++;
	}
	tmp = malloc((j + 1) * sizeof(char *));
	printf("qtd malocada: %i\n", j + 1);
	i = 0;
	k = 0;
	while(s[i])
	{
		j = 0;
		if (s[i][0] != q)
		{
			tmp2 = ft_split(s[i], ' ');
			while (tmp2[j])
			{
				tmp[k] = ft_substr(tmp2[j], 0, ft_strlen(tmp2[j]));
				j++;
				k++;
			}
			i++;
		}
		else //if (s[i][0] == q)
		{
			tmp[k] = ft_substr(s[i], 0, ft_strlen(s[i]));
			k++;
			i++;
		}
		printf("[i] %i\n", i);
		printf("[k] %i\n", k);
	}
	tmp[k] = NULL;
	return (tmp);
}


// # Arrage
char	*test_split_quotes(void)
{
	char 	*teste = "um \'teste maluco\'";
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
