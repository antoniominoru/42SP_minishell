/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:53:57 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/21 02:14:06 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(char *cmd)
{
	if (ft_strnstr(cmd, "-n ", 7))
		printf("%s", cmd + 3);
	else
		printf("%s\n", cmd);
}
