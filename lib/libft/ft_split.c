/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:30:25 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/27 02:31:53 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length_word(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		counter++;
	}
	return (counter);
}

static int	count_words(char const *s, char c)
{
	int	is_word;
	int	how_many;
	int	i;

	i = 0;
	is_word = 0;
	how_many = 0;
	while (s[i])
	{
		if (is_word == 0 && s[i] != c)
		{
			is_word = 1;
			how_many++;
		}
		else if (is_word && s[i] == c)
			is_word = 0;
		i++;
	}
	return (how_many);
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
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		if (s[i] != c)
		{
			*table = ft_substr(&s[i], 0, length_word(&s[i], c));
			if (!table)
			{
				free_table(table);
				return (NULL);
			}
			i += length_word(&s[i], c);
			table++;
		}
	}
	*table = NULL;
	return (table_ptr);
}

char	**ft_split(char const *s, char c)
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
