/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:53:57 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/18 01:24:19 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	echo_is_empty(char **cmd_tkn)
{
	if (cmd_tkn[1] == NULL)
	{
		printf("\n");
		return (1);
	}
	else if (!ft_strncmp(cmd_tkn[1], "-n\0", 3)
		&& cmd_tkn[2] == NULL && ft_strlen(cmd_tkn[1]) == 2)
		return (1);
	return (0);
}

static	void	print_echo_flag_n(char **cmd_tkn)
{
	int	i;

	i = 1;
	while (cmd_tkn[i++])
	{
		if (cmd_tkn[i] == NULL)
		{	
			break ;
		}
		else
		{
			if (cmd_tkn[i + 1] == NULL)
				printf("%s", cmd_tkn[i]);
			else
				printf("%s ", cmd_tkn[i]);
		}
	}
}

static	void	print_echo(char **cmd_tkn)
{
	int	i;

	i = 0;
	while (cmd_tkn[i++])
	{
		if (cmd_tkn[i] == NULL)
		{	
			printf("\n");
			break ;
		}
		else
			if (cmd_tkn[i + 1] == NULL)
				printf("%s", cmd_tkn[i]);
			else
				printf("%s ", cmd_tkn[i]);
	}
}

static	char	**env_var(char **cmd_tkn, t_list **envp)
{
	int		i;
	char	**cmd_tkn_env;
	char	*swap_cmd;

	i = 0;
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
		}
		i++;
	}
	return (cmd_tkn_env);
}

void	builtin_echo(char **cmd_tkn, t_list **envp)
{
	char	**cmd_tkn_env;

	if (envp == NULL)
		return ;
	if (echo_is_empty(cmd_tkn))
		return ;
	cmd_tkn_env = env_var(cmd_tkn, envp);
	if (ft_strncmp(cmd_tkn[1], "-n\0", 3) == 0)
		print_echo_flag_n(cmd_tkn);
	else
		print_echo(cmd_tkn);
}
