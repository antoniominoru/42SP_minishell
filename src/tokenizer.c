/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:05:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/18 17:52:11 by jvictor-         ###   ########.fr       */
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

static int		hav_env_var(char **cmd, int i)
{
	char	*tmp;
	
	if(!ft_strncmp(cmd[i], "$", 1) 
		&& ft_strlen(cmd[i]) > 1
		&& !ft_strchr(cmd[i], '\"'))
		return (1);
	else if (!ft_strncmp(cmd[i], "\"", 1)
				&& !ft_strncmp(&cmd[i][1], "$", 1))
	{
		tmp = cmd[i];
		cmd[i] = ft_strtrim(cmd[i], "\"");
		return(1);
	}
	else if (!ft_strncmp(cmd[i], "$", 1)
				&& ft_strchr(cmd[i], '\"'))
	{
		tmp = cmd[i];
		cmd[i] = ft_strtrim(cmd[i], "\"");
		return(1);
	}
	// printf("%s", &cmd[i][ft_strlen(cmd[i]) - 1]);
	//precisa de mais um if, verificando quando tem na palavra uma aspas no final
	return (0);
	// echo "$HOME"
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

static char	what_is_the_quote(char *cmd)
{
	int i;
	
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
	char	**quotes;
	char	q;
	char	*cmd_env_new;
	// int		i = 0;
	// int		j = 0;
	(void)envp;


	cmd_tkn_new = NULL;
	if (cmd_tkn != NULL)
		free_tkn(cmd_tkn);
	//precisa colar um if pra verificar qual é a aspas desses comandos
	q = what_is_the_quote(cmd);

	if (q != '\'')
	{
		cmd_tkn_new = ft_split(cmd, ' ');
		cmd_tkn_new = env_var(cmd_tkn_new, envp, count_words(cmd, ' '));
		// while (cmd_tkn_new[i])
		// 	printf("posição env_var[%i] ->$%s\n\n", j++, cmd_tkn_new[i++]);
		// i = 0;
		// j = 0;
		cmd_env_new = ft_new_string(cmd_tkn_new);
		// while (cmd_tkn_new[i])
		// 	printf("posição ft_new_string[%i] ->$%s\n\n", j++, cmd_tkn_new[i++]);
		// i = 0;
		// j = 0;
		// printf("string:%s\n\n\n\n", cmd_env_new);
	}
	else
		cmd_env_new = ft_strdup(cmd);
	quotes = split_quotes(cmd_env_new, q);
	// while (cmd_tkn_new[i])
	// 	printf("posição split_quotes [%i] ->$%s\n\n", j++, cmd_tkn_new[i++]);
	cmd_tkn_new = split_space_quotes(quotes, q);
	cmd_tkn_new = remove_quotes(cmd_tkn_new, q);

	// while (cmd_tkn_new[i])
	// 	printf("posição FINAL[%i] ->$%s\n\n", j++, cmd_tkn_new[i++]);
	// printf("---------------------\n");
	return (cmd_tkn_new);
}
