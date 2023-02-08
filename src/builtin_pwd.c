/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:53:15 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/08 01:27:17 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(void)
{
	char	*pwd;

	g_current_status = NO_ERROR;
	pwd = getcwd(NULL, 0);
	if (pwd)
		printf("%s\n", pwd);
	else
		status_error("Error: PWD", ERROR);
	free(pwd);
}
