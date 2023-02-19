/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:03:59 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/17 19:15:06 by jvictor-         ###   ########.fr       */
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
