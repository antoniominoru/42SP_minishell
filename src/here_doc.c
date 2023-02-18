/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:00:46 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/18 01:01:22 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inter_here_doc(int signal)
{
	(void)signal;
	g_current_status = 130;
	write(1, "\n", 1);
	exit(130);
}

void	error_here_doc(void)
{
	char	*error;

	error = ft_strdup("minishell: warning: here-document \
	delimited by end-of-file");
	ft_putendl_fd(error, 2);
	g_current_status = 0;
	free(error);
}

void	here_doc_teminal(int fd_tmp, char *eof)
{
	char	*term;

	signal(SIGINT, inter_here_doc);
	while (1)
	{
		term = readline("> ");
		if (!term)
		{
			error_here_doc();
			close(fd_tmp);
			exit(0);
		}
		if (v_exit_hd(term, eof))
			ft_putendl_fd(term, fd_tmp);
		else
		{
			close(fd_tmp);
			free(term);
			break ;
		}
		free(term);
	}
	exit(0);
}

void	here_doc(int *fd, char *eof)
{
	int	fd_tmp;
	int	fd_out_saved;
	int	pid;
	int	status;

	fd_tmp = tmp_file();
	if (fd_tmp == -1)
		return ;
	fd_out_saved = dup(1);
	dup2(fd[1], STDOUT_FILENO);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		here_doc_teminal(fd_tmp, eof);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		clear_tmp_file();
		g_current_status = 130;
	}
	make_tmp_file();
	dup2(fd_out_saved, STDOUT_FILENO);
	close(fd_out_saved);
}

int	here_doc_main(int *fd, char **eof, char *redic)
{
	int	pos;

	pos = ft_tknredirect(eof, redic, 1) + 1;
	here_doc(fd, eof[pos]);
	return (pos);
}
