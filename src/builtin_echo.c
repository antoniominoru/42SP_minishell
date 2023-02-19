/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:53:57 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/19 06:51:08 by jvictor-         ###   ########.fr       */
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
		{
			if (cmd_tkn[i + 1] == NULL)
				printf("%s", cmd_tkn[i]);
			else
				printf("%s ", cmd_tkn[i]);
		}
	}
}

void	builtin_echo(char **cmd_tkn)
{
	if (echo_is_empty(cmd_tkn))
		return ;
	if (ft_strncmp(cmd_tkn[1], "-n\0", 3) == 0)
		print_echo_flag_n(cmd_tkn);
	else
		print_echo(cmd_tkn);
	g_current_status = NO_ERROR;
}
