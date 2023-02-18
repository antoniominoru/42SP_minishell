/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:05:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/18 02:31:48 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**allocate(char **s, int *j, int how_many, char **other)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < how_many - 1)
	{
		if (i == *j)
		{
			k++;
		}
		other[i] = ft_substr(s[k], 0, ft_strlen(s[k]));
		if (!other)
		{
			free_tkn(other);
			return (NULL);
		}
		i++;
		k++;
	}
	--*j;
	other[i] = NULL;
	return (other);
}

char	**reallocate_cmd(char **s, int *j, int how_many)
{
	char	**other;

	other = NULL;
	other = malloc(how_many * sizeof(char *));
	if (!other)
		return (NULL);
	other = allocate(s, j, how_many, other);
	free_tkn(s);
	return (other);
}

// static void	swap_env(char **cmd_tkn_env, t_list **envp, int i)
// {
// 	char	*swap_cmd;

// 	swap_cmd = ft_strdup(&cmd_tkn_env[i][1]);
// 	free(cmd_tkn_env[i]);
// 	cmd_tkn_env[i] = ft_strdup(take_value_of_env(swap_cmd, envp));
// 	free(swap_cmd);
// }

// static	char	**env_var(char **cmd_tkn, t_list **envp, int how_many)
// {
// 	int		i;
// 	char	**cmd_tkn_env;

// 	i = 0;
// 	if (envp == NULL)
// 		return (NULL);
// 	cmd_tkn_env = cmd_tkn;
// 	while (cmd_tkn_env[i])
// 	{
// 		if (!ft_strncmp(cmd_tkn_env[i], "$", 1)
// 			&& ft_strlen(cmd_tkn_env[i]) > 1)
// 		{
// 			if (take_value_of_env(&cmd_tkn_env[i][1], envp))
// 				swap_env(cmd_tkn_env, envp, i);
// 			else if (!ft_strncmp(cmd_tkn_env[i], "$?", 2))
// 				{
// 					free(cmd_tkn_env[i]);
// 					cmd_tkn_env[i] = ft_itoa(g_current_status);
// 				}
// 			else
// 				cmd_tkn_env = reallocate_cmd(cmd_tkn_env, &i, how_many--);
// 		}
// 		i++;
// 	}
// 	return (cmd_tkn_env);
// }

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

static char	**remove_quotes(char **s, char q)
{
	char	**tmp;
	int 	i;
	int		pp_len;

	i = 0;
	pp_len = ft_strlen_pp(s);
	tmp = NULL;
	tmp = malloc((pp_len + 1) * sizeof(char *));
	while(s[i])
	{
		if(s[i][0] == q)
		{
			if (s[i][0] == q && s[i][1] == q)
				tmp[i] = ft_strdup("");
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

static char	**split_space_quotes(char **s, char q)
{
	char	**tmp;
	int		qt_mem_allocate;

	tmp = NULL;
	qt_mem_allocate = count_space_quotes(s, q);
	tmp = malloc((qt_mem_allocate + 1) * sizeof(char **));
	tmp = core_space_quotes(s, tmp, q);
	tmp = remove_quotes(tmp, q);
	return (tmp);
}

char	**tokenizer(char *cmd, char **cmd_tkn, t_list **envp)
{
	char	**cmd_tkn_new;
	char	**quotes;
	// int		i = 0;
	// int		j = 0;
	(void)envp;

	if (cmd_tkn != NULL)
		free_tkn(cmd_tkn);
	//precisa colar um if pra verificar qual é a aspas desses comandos
	quotes = split_quotes(cmd, '\"');
	cmd_tkn_new = split_space_quotes(quotes, '\"');
	// while (cmd_tkn_new[i])
	// 	printf("posição [%i] ->$%s\n\n", j++, cmd_tkn_new[i++]);
	//cmd_tkn_new = env_var(cmd_tkn_new, envp, count_words(cmd, ' '));
	// printf("---------------------\n");
	return (cmd_tkn_new);
}
