/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:23:46 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/06 00:53:10 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	status_error(char *msg, int error_status)
{
	char		*msg_error;

	if (msg)
	{
		msg_error = ft_strjoin("(miniHELL error): ", msg);
		printf("%s\n", msg_error);
		free(msg_error);
	}
	g_current_status = error_status;
}
