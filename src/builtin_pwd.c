/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:53:15 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/14 01:39:44 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd)
		printf("%s\n", pwd);
	else
		printf("Error: PWD");
	return (1);
}
