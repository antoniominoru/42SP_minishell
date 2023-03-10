/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_verify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:06:40 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/20 10:25:00 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_caract(char *cmd, char *caract)
{
	int	i;
	int	j;

	i = ft_strlen(cmd);
	j = ft_strlen(caract);
	if (i == j && !ft_strncmp(cmd, caract, j))
		return (j);
	return (0);
}

int	ft_tknredirect(char **cmd, char *cart, int flag)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = cmd;
	while (tmp[i])
	{
		if (ft_is_caract(tmp[i], cart) && flag == 0 && ft_strlen(tmp[i]) < 3)
			return (ft_is_caract(tmp[i], cart));
		if (ft_is_caract(tmp[i], cart) && flag == 1 && ft_strlen(tmp[i]) < 3)
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
	int		fd;
	int		pos;
	char	*command;

	pos = ft_tknredirect(cmd, redic, 1) + 1;
	command = ft_strjoin("/bin/", cmd[0]);
	if (access(command, 0) != 0)
		return (pos);
	fd = 0;
	if (io_re == 0)
		fd = open(cmd[pos], config);
	else if (io_re == 1)
		fd = open(cmd[pos], config, 0777);
	dup2(fd, io_re);
	close(fd);
	free(command);
	return (pos);
}

char	**redirect_verify(char **cmd, int *old_in)
{
	int	pos;

	pos = 0;
	if (!old_in)
		printf("error\n");
	if (count_vector(cmd) < 3)
		return (cmd);
	if (ft_tknredirect(cmd, ">", 0) == 1)
		pos = io_redirect(cmd, O_WRONLY | O_CREAT | O_TRUNC, 1, ">");
	else if (ft_tknredirect(cmd, ">>", 0) == 2)
		pos = io_redirect(cmd, O_WRONLY | O_CREAT | O_APPEND, 1, ">>");
	else if (ft_tknredirect(cmd, "<", 0) == 1)
		pos = io_redirect(cmd, O_RDONLY | O_CREAT, 0, "<");
	else if (ft_tknredirect(cmd, "<<", 0) == 2)
		pos = here_doc_main(old_in, cmd, "<<");
	if (pos != 0)
	{
		cmd = reallocate_cmd(cmd, &pos, count_vector(cmd));
		cmd = reallocate_cmd(cmd, &pos, count_vector(cmd));
	}
	return (cmd);
}
