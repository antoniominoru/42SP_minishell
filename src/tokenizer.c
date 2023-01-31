/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:05:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/31 01:21:09 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**allocate(char **s, int *j, int how_many, char **other)
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

static	char	**env_var(char **cmd_tkn, t_list **envp, int how_many)
{
	int		i;
	char	**cmd_tkn_env;
	char	*swap_cmd;

	i = 0;
	if (envp == NULL)
		return (NULL);
	cmd_tkn_env = cmd_tkn;
	while (cmd_tkn_env[i])
	{
		if (!ft_strncmp(cmd_tkn_env[i], "$", 1)
			&& ft_strlen(cmd_tkn_env[i]) > 1)
		{
			if (take_value_of_env(&cmd_tkn_env[i][1], envp))
			{
				swap_cmd = ft_strdup(&cmd_tkn_env[i][1]);
				free(cmd_tkn_env[i]);
				cmd_tkn_env[i] = ft_strdup(take_value_of_env(swap_cmd, envp));
				free(swap_cmd);
			}
			else
			{
				char **other = malloc(how_many * sizeof(char *));
				if (!other)
					return (NULL);
				other = allocate(cmd_tkn_env, &i, how_many--, other);
				cmd_tkn_env = other;
			}
		}
		i++;
	}
	return(cmd_tkn_env);
}

char	**tokenizer(char *cmd, char **cmd_tkn, t_list **envp)
{
	char	**cmd_tkn_new;

	if (cmd_tkn != NULL)
		free_tkn(cmd_tkn);
	cmd_tkn_new = ft_split(cmd, ' ');
	cmd_tkn_new = env_var(cmd_tkn_new, envp, count_words(cmd, ' '));
	return (cmd_tkn_new);
}
