/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all_complement.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:09:31 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/18 02:31:30 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_token(char **cmd_tkn)
{
	int		c_pipe;
	int		c_loop;
	int		c_new_tkn;
	char	*tmp;
	char	**fim;

	c_loop = 0;
	c_new_tkn = 0;
	tmp = NULL;
	fim = NULL;
	c_pipe = cont_pipe_token(cmd_tkn);
	fim = malloc((c_pipe + 2) * sizeof(char *));
	while (cmd_tkn[c_loop] != NULL)
	{
		if (!ft_strncmp(cmd_tkn[c_loop], "|", 1))
		{
			fim[c_new_tkn] = tmp;
			tmp = NULL;
			c_new_tkn++;
			c_loop++;
		}
		if (tmp == NULL)
			tmp = ft_strdup(" \"");
		else
			tmp = ft_strjoin(tmp, " \"");
		tmp = ft_strjoin(tmp, cmd_tkn[c_loop]);
		tmp = ft_strjoin(tmp, "\" ");
		c_loop++;
	}
	fim[c_new_tkn] = tmp;
	fim[c_new_tkn + 1] = NULL;
	return (fim);
}
