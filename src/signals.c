/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 03:06:22 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/11 19:39:43 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		g_current_status = 130;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sig_handler_fork(int signal)
{
	if (signal == SIGINT)
	{
		g_current_status = 130;
		write(1, "\n", 1);
	}
	else if (signal == SIGQUIT)
	{
		g_current_status = 131;
		printf("Quit (core dumped)\n");
	}
	else if (signal == SIGUSR1)
	{
		status_error("Command not found", 127);
	}
}

void	define_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	define_signals_fork(void)
{
	signal(SIGINT, sig_handler_fork);
	signal(SIGQUIT, sig_handler_fork);
	signal(SIGUSR1, sig_handler_fork);
}
