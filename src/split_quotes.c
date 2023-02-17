/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:03:59 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/17 15:59:35 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	length_word(char const *s, char c)
{
	size_t	counter;
	size_t	i;
	size_t	hmany_c;

	counter = 0;
	i = 0;
	hmany_c = 0;
	while (s[i] && s[i] == c)
		i++;
	hmany_c = i;
	while (s[i] && s[i] != c)
	{
		i++;
		counter++;
	}
	return (counter + hmany_c);
}

static size_t	length_word_2(char const *s, char c)
{
	size_t	counter;
	size_t	i;
	size_t	hmany_c;

	counter = 0;
	i = 0;
	hmany_c = 0;
	while (s[i] && s[i] == c)
		i++;
	hmany_c = i;
	while (s[i] && s[i] != c)
	{
		i++;
		counter++;
	}
	if (s[i] == c)
		hmany_c++;
	return (counter + hmany_c);
}

static void	free_table(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	**allocates(char const *s, char c, char **table, char **table_ptr)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			*table = ft_substr(&s[i], 0, length_word(&s[i], c));
			i += length_word(&s[i], c);
		}
		else
		{
			*table = ft_substr(&s[i], 0, length_word_2(&s[i], c));
			i += length_word_2(&s[i], c);
		}
		if (!table)
		{
			free_table(table);
			return (NULL);
		}
		table++;
	}
	*table = NULL;
	return (table_ptr);
}

//char	**split_space_quotes(char **s)
//{
//	char	**tmp;
//	char	**tmp_2;
//	int		i;
//	int		j;
//
//	i = 0;
//	j = 0;
//	tmp = NULL;
//	while(s[i])
//	{
//		if (s[i][0] == '\"' || s[i][0] == '\'')
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			tmp = ft_split(s[i], ' ');
//			j += ft_strlen_pp(tmp);
//			free(tmp);
//			i++;
//		}
//	}
//	tmp_2 = malloc((j + 1) * sizeof(char *));
//	free(tmp_2);
//}

// static char	**split_space_quotes(char **s, char q)
// {
// 	char	**tmp;
// 	char	**tmp2;
// 	int		i;
// 	int		j;
// 	int		k;

// 	i = 0;
// 	j = 0;
// 	tmp = NULL;
// 	tmp2 = NULL;
// 	while(s[i])
// 	{
// 		if (s[i][0] != q)
// 			j += count_words(s[i], ' ');
// 		else if (s[i][0] == q)
// 			j++;
// 		i++;
// 	}
// 	tmp = malloc((j + 1) * sizeof(char *));
// 	printf("qtd malocada: %i\n", j + 1);
// 	i = 0;
// 	k = 0;
// 	while(s[i])
// 	{
// 		j = 0;
// 		if (s[i][0] != q)
// 		{
// 			tmp2 = ft_split(s[i], ' ');
// 			while (tmp2[j])
// 			{
// 				tmp[k] = ft_substr(tmp2[j], 0, ft_strlen(tmp2[j]));
// 				j++;
// 				k++;
// 			}
// 			i++;
// 		}
// 		else //if (s[i][0] == q)
// 		{
// 			tmp[k] = ft_substr(s[i], 0, ft_strlen(s[i]));
// 			k++;
// 			i++;
// 		}
// 		printf("[i] %i\n", i);
// 		printf("[k] %i\n", k);
// 	}
// 	tmp[k] = NULL;
// 	return (tmp);
// }

//int	ft_strlen_pp(char **str)
//{
//	int	i;
//
//	i = 0;
//	while (str[i])
//		i++;
//	return (i);
//}

char	**split_quotes(char const *s, char c)
{
	char	**table;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	table = malloc((words + 1) * sizeof(char *));
	if (!table)
		return (NULL);
	table = allocates(s, c, table, table);
	if (!table)
		return (NULL);
	return (table);
}
