/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_two_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:44:11 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/19 08:17:50 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	have_two_quotes(char *cmd)
{
	int	q_single;
	int	q_double;
	int	len;

	len = ft_strlen(cmd) - 1;
	q_single = 0;
	q_double = 0;
	while (len)
	{
		if (cmd[len] == '\'')
			q_single++;
		if (cmd[len] == '\"')
			q_double++;
		len--;
	}
	if (cmd[len] == '\'')
		q_single++;
	if (cmd[len] == '\"')
		q_double++;
	if (q_single % 2 != 0 || q_double % 2 != 0)
		return (-1);
	if (q_single == 2 || q_double == 2)
		return (1);
	if (q_single > 2 || q_double > 2)
		return (2);
	return (0);
}
