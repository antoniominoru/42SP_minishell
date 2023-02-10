/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:05:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/10 15:45:52 by aminoru-         ###   ########.fr       */
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

static void	swap_env(char **cmd_tkn_env, t_list **envp, int i)
{
	char	*swap_cmd;

	swap_cmd = ft_strdup(&cmd_tkn_env[i][1]);
	free(cmd_tkn_env[i]);
	cmd_tkn_env[i] = ft_strdup(take_value_of_env(swap_cmd, envp));
	free(swap_cmd);
}

static	char	**env_var(char **cmd_tkn, t_list **envp, int how_many)
{
	int		i;
	char	**cmd_tkn_env;

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
				swap_env(cmd_tkn_env, envp, i);
			else
				cmd_tkn_env = reallocate_cmd(cmd_tkn_env, &i, how_many--);
		}
		i++;
	}
	return (cmd_tkn_env);
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
