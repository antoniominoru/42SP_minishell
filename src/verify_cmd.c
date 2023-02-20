/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:17:17 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/20 09:53:01 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	initial_verify_cmd(char **cmd)
{
	if (!ft_strncmp(cmd[0], ".", 1))
		return (-1);
	if (!ft_strncmp(cmd[0], "./", 2))
		return (-1);
	if (!ft_strncmp(cmd[0], "/", 1))
		return (-1);
	if (!ft_strncmp(cmd[0], "|", 1))
		return (-1);
	return (0);
}

int	verify_cmd(char **cmd)
{
	if (ft_strlen(cmd[0]) < 3 && count_vector(cmd) == 1)
		if (initial_verify_cmd(cmd) == -1)
			return (-1);
	if (!ft_strncmp(cmd[0], "|", 1))
		return (-1);
	if (!ft_strncmp(cmd[0], "/", 1))
		return (-1);
	while (*cmd)
	{
		if (!ft_strncmp(*cmd, "||", 2))
			return (-1);
		if (!ft_strncmp(*cmd, "\\", 2))
			return (-1);
		if (!ft_strncmp(*cmd, ";", 1))
			return (-1);
		if (!ft_strncmp(*cmd, ">>>", 3))
			return (-1);
		if (!ft_strncmp(*cmd, "<<<", 3))
			return (-1);
		cmd++;
	}
	return (0);
}

int	init_verify_cmd(t_list **envp, char **split_token,
						char **cmd_tkn, char *cmd)
{
	int		old_in;
	t_all	all;

	old_in = 0;
	if (verify_cmd(cmd_tkn) == -1)
	{
		status_error("Invalid caracter", ERROR);
		return (0);
	}
	else
	{
		all.cmd = cmd;
		all.split_token = split_token;
		all.envp = envp;
		all.old_in = &old_in;
		line_in_pipe1(&all, 0);
	}
	return (old_in);
}
