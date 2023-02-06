/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/06 02:03:36 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	count_args(char **cmd_tkn)
{
	int	i;

	i = 0;
	while (cmd_tkn[i])
		i++;
	return (i);
}

static	int	arg_not_num(char *cmd_tkn)
{
	if (!cmd_tkn)
		return (0);
	while (*cmd_tkn)
		if (!ft_isdigit(*cmd_tkn++))
			return (1);
	return (0);
}

void	exit_minishell(t_list **lst_env, char *cmd,
								char **cmd_tkn, int arg_exit)
{
	free_all(lst_env, cmd, cmd_tkn);
	printf("exit\n");
	exit(arg_exit);
}

void	builtin_exit(t_list **lst_env, char *cmd, char **cmd_tkn)
{
	int	argc;

	argc = count_args(cmd_tkn);
	if (arg_not_num(cmd_tkn[1]))
	{
		status_error("exit: error, numeric argument required.", ERROR);
		exit_minishell(lst_env, cmd, cmd_tkn, g_current_status);
	}
	if (argc > 2)
	{
		status_error("exit: error, too many args.", ERROR);
		return ;
	}
	if (cmd_tkn[1])
		g_current_status = atoi(cmd_tkn[1]);
	exit_minishell(lst_env, cmd, cmd_tkn, g_current_status);
}
