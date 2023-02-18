/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:05:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/18 18:57:59 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hav_env_var(char **cmd, int i)
{
	char	*tmp;

	if (!ft_strncmp(cmd[i], "$", 1)
		&& ft_strlen(cmd[i]) > 1
		&& !ft_strchr(cmd[i], '\"'))
		return (1);
	else if (!ft_strncmp(cmd[i], "\"", 1) && !ft_strncmp(&cmd[i][1], "$", 1))
	{
		tmp = cmd[i];
		cmd[i] = ft_strtrim(cmd[i], "\"");
		return (1);
	}
	else if (!ft_strncmp(cmd[i], "$", 1) && ft_strchr(cmd[i], '\"'))
	{
		tmp = cmd[i];
		cmd[i] = ft_strtrim(cmd[i], "\"");
		return (1);
	}
	return (0);
}

char	**env_var(char **cmd_tkn, t_list **envp, int how_many)
{
	int		i;
	char	**cmd_tkn_env;

	i = 0;
	if (envp == NULL)
		return (NULL);
	cmd_tkn_env = cmd_tkn;
	while (cmd_tkn_env[i])
	{
		if (hav_env_var(cmd_tkn_env, i))
		{
			if (take_value_of_env(&cmd_tkn_env[i][1], envp))
				swap_env(cmd_tkn_env, envp, i);
			else if (!ft_strncmp(cmd_tkn_env[i], "$?", 2))
			{
				free(cmd_tkn_env[i]);
				cmd_tkn_env[i] = ft_itoa(g_current_status);
			}
			else
				cmd_tkn_env = reallocate_cmd(cmd_tkn_env, &i, how_many--);
		}
		i++;
	}
	return (cmd_tkn_env);
}

char	what_is_the_quote(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\"')
			return ('\"');
		else if (cmd[i] == '\'')
			return ('\'');
		i++;
	}
	return ('\0');
}

char	**tokenizer(char *cmd, char **cmd_tkn, t_list **envp)
{
	char	**cmd_tkn_new;
	char	q;
	char	*cmd_env_new;

	cmd_tkn_new = NULL;
	if (cmd_tkn != NULL)
		free_tkn(cmd_tkn);
	q = what_is_the_quote(cmd);
	if (q != '\'')
	{
		cmd_tkn_new = ft_split(cmd, ' ');
		cmd_tkn_new = env_var(cmd_tkn_new, envp, count_words(cmd, ' '));
		cmd_env_new = ft_new_string(cmd_tkn_new);
	}
	else
		cmd_env_new = ft_strdup(cmd);
	cmd_tkn_new = split_space_quotes(split_quotes(cmd_env_new, q), q);
	cmd_tkn_new = remove_quotes(cmd_tkn_new, q);
	return (cmd_tkn_new);
}
