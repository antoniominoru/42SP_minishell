
#include "minunit.h"
// # Arrage
char	*test_split_quotes(void)
{
	char 	*teste = "\"eu\" \"sou\" \"maluco\" \"etc\" \"jjj\" \"pra\" \"caramba\"";
	char 	**quotes;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	quotes = NULL;
	quotes = split_quotes(teste, '\"');
	printf("string: %s\n\n", teste);
	while (quotes[i])
		printf("posição [%i] ->%s\n\n", j++, quotes[i++]);

	// // # Assert
	// mu_assert("ERROR: test_split_quotes", !strcmp(teste, quotes[1]));
	return (0);
}
