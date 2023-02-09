/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_verify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:06:40 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/09 23:49:38 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isredirect(char *cmd, char *redirect)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == redirect[0] && \
			cmd[i - 1] != redirect[0] && \
			cmd[i + 1] != redirect[0]
		)
			return (1);
		if (cmd[i] == redirect[0] && \
			cmd[i - 1] != redirect[0] && \
			cmd[i + 1] == redirect[0] && \
			cmd[i + 2] != redirect[0]
		)
			return (2);
		i++;
	}
	return (0);
}

static int	ft_tknredirect(char **cmd, char *redirect, int flag)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = cmd;
	while (tmp[i])
	{
		if (ft_isredirect(tmp[i], redirect) && flag == 0)
			return (ft_isredirect(tmp[i], redirect));
		if (ft_isredirect(tmp[i], redirect) && flag == 1)
			return (i);
		i++;
	}
	return (0);
}

int	count_vector(char **cmd)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = cmd;
	while (tmp[i])
		i++;
	return (i);
}

static int	io_redirect(char **cmd, int config, int io_re, char *redic)
{
	int	fd;
	int	pos;

	pos = ft_tknredirect(cmd, redic, 1) + 1;
	fd = 0;
	if (io_re == 0)
		fd = open(cmd[pos], config);
	else if (io_re == 1)
		fd = open(cmd[pos], config, 0777);
	dup2(fd, io_re);
	close(fd);
	return (pos);
}

char	**redirect_verify(char **cmd, int *old_in)
{
	int	pos;

	pos = 0;
	if (!old_in)
		printf("error\n");
	if (ft_tknredirect(cmd, ">", 0) == 1)
		pos = io_redirect(cmd, O_WRONLY | O_CREAT | O_TRUNC, 1, ">");
	else if (ft_tknredirect(cmd, ">>", 0) == 2)
		pos = io_redirect(cmd, O_WRONLY | O_CREAT | O_APPEND, 1, ">>");
	else if (ft_tknredirect(cmd, "<", 0) == 1)
		pos = io_redirect(cmd, O_RDONLY | O_CREAT, 0, "<");
	else if (ft_tknredirect(cmd, "<<", 0) == 2)
		printf("redirect_verify - <<\n");
	if (pos != 0)
	{
		cmd = reallocate_cmd(cmd, &pos, count_vector(cmd));
		cmd = reallocate_cmd(cmd, &pos, count_vector(cmd));
	}
	return (cmd);
}
