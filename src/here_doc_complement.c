/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_complement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:00:19 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/18 01:01:05 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tmp_file(void)
{
	int		fd;
	char	*error;

	error = NULL;
	fd = open(T_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		error = ft_strjoin("minishell: redirect:", strerror(errno));
		ft_putendl_fd(error, 2);
		g_current_status = 1;
		free(error);
	}
	return (fd);
}

int	v_exit_hd(char	*term, char *eof)
{
	if (ft_strlen(term) == ft_strlen(eof))
		if (ft_strncmp(term, eof, ft_strlen(eof)) == 0)
			return (0);
	return (1);
}

void	clear_tmp_file(void)
{
	int	fd;

	fd = open(T_FILE, O_WRONLY | O_TRUNC, 0600);
	close(fd);
}

void	make_tmp_file(void)
{
	int	fd;

	fd = open(T_FILE, O_RDONLY);
	unlink(T_FILE);
	dup2(fd, 0);
	close(fd);
}
