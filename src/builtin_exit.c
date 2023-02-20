/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/20 08:07:41 by aminoru-         ###   ########.fr       */
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

void	exit_m_sh(t_list **lst_env, char *cmd,
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
		status_error("exit: error, numeric argument required.", ERROR_TWO);
		exit_m_sh(lst_env, cmd, cmd_tkn, g_current_status);
	}
	if (argc > 2)
	{
		status_error("exit: error, too many args.", ERROR_ONE);
		return ;
	}
	if (cmd_tkn[1])
		g_current_status = atoi(cmd_tkn[1]);
	exit_m_sh(lst_env, cmd, cmd_tkn, g_current_status);
}

void	builtin_exit1(t_all *all, char **cmd_tkn)
{
	int	argc;

	argc = count_args(cmd_tkn);
	if (arg_not_num(cmd_tkn[1]))
	{
		status_error("exit: error, numeric argument required.", ERROR_TWO);
		exit_m_sh1(all, cmd_tkn, g_current_status);
	}
	if (argc > 2)
	{
		status_error("exit: error, too many args.", ERROR_ONE);
		return ;
	}
	if (cmd_tkn[1])
		g_current_status = atoi(cmd_tkn[1]);
	exit_m_sh1(all, cmd_tkn, g_current_status);
}

void	exit_m_sh1(t_all *all, char **cmd_tkn, int arg_exit)
{
	free_all(all->envp, all->cmd, cmd_tkn);
    free_tkn(all->split_token);
	printf("exit\n");
	exit(arg_exit);
}
