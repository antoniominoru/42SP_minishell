/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:05:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/18 14:28:37 by jvictor-         ###   ########.fr       */
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
	(void)envp;

	if (cmd_tkn != NULL)
		free_tkn(cmd_tkn);
	//precisa colar um if pra verificar qual é a aspas desses comandos
	q = what_is_the_quote(cmd);

	//se não for aspas simples
		//splitar por espacos
		//cmd_tkn_new = env_var(cmd_tkn_new, envp, count_words(cmd, ' '));
		
	quotes = split_quotes(cmd, q);
	cmd_tkn_new = split_space_quotes(quotes, q);
	cmd_tkn_new = remove_quotes(cmd_tkn_new, q);

	// while (cmd_tkn_new[i])
	// 	printf("posição [%i] ->$%s\n\n", j++, cmd_tkn_new[i++]);
	
	
	// printf("---------------------\n");
	return (cmd_tkn_new);
}
