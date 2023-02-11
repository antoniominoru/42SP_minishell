/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:00:46 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/11 15:37:33 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define T_FILE "/tmp/minishell_tmp"

static int	tmp_file(void)
{
	int	fd;

	fd = open(T_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		printf("Error\n");
	return (fd);
}
static int v_exit_hd(char	*term, char *eof)
{
	if (ft_strlen(term) == ft_strlen(eof))
		if (ft_strncpm(term, eof, ft_strlen(eof)) == 0)
			return (0);
	return (1);
}

static void	put_in_doc(char	*term, int fd_tmp)
{
	
}

static void	clear_tmp_file(void)
{
	int	fd;

	fd = open(T_FILE, O_WRONLY | O_TRUNC, 0600);
	close(fd);
}

static void	make_tmp_file(void)
{
	int	fd;

	fd = open(T_FILE, O_RDONLY);
	unlink(T_FILE);
	dup2(fd, 0);
	close(fd);
}

static void	here_doc_teminal(int fd_tmp, char *eof)
{
	char	*term;

	signal(SIGINT, inter_here_doc);
	while (1)
	{
		term = readline("> ");
		if (!term)
		{
			printf("Error\n");
			close(fd_tmp);
			exit(0);
		}
		if (v_exit_hd(term, eof))
			put_in_doc(term, fd_tmp);
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
	if (fd_tmp = -1)
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
