/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:59:03 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/20 09:12:13 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	free_tkn(tmp2);
}

static	int	count_space_quotes(char **s, char q)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i][0] != q)
			j += count_words(s[i], ' ');
		else if (s[i][0] == q)
			j++;
		i++;
	}
	return (j);
}

static char	**core_space_quotes(char **s, char **tmp, char q)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (s[i])
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
	return (tmp);
}

char	**remove_quotes(char **s, char q)
{
	char	**tmp;
	int		i;
	int		pp_len;

	i = 0;
	pp_len = ft_strlen_pp(s);
	tmp = NULL;
	tmp = malloc((pp_len + 1) * sizeof(char *));
	while (s[i])
	{
		if (s[i][0] == q)
		{
			if (s[i][0] == q && s[i][1] == q && !s[i][2])
				tmp[i] = ft_strdup(" ");
			else
				tmp[i] = ft_strtrim(s[i], &q);
		}
		else
			tmp[i] = ft_strdup(s[i]);
		i++;
	}
	tmp[i] = NULL;
	free_tkn(s);
	return (tmp);
}

char	**split_space_quotes(char **s, char q)
{
	char	**tmp;
	int		qt_mem_allocate;

	tmp = NULL;
	qt_mem_allocate = count_space_quotes(s, q);
	tmp = malloc((qt_mem_allocate + 1) * sizeof(char *));
	tmp = core_space_quotes(s, tmp, q);
	return (tmp);
}
