/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all_complement.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:09:31 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/18 14:41:17 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_token(char **cmd_tkn)
{
	int		c_all;
	char	*tmp;
	char	**end;

	c_all = 0;
	tmp = NULL;
	end = malloc((cont_pipe_token(cmd_tkn) + 2) * sizeof(char *));
	while (*cmd_tkn)
	{
		if (!ft_strncmp(*cmd_tkn, "|", 1))
		{
			end[c_all] = tmp;
			tmp = NULL;
			c_all++;
			cmd_tkn++;
		}
		if (tmp == NULL)
			tmp = ft_strdup(" \"");
		else
			tmp = ft_strjoin(tmp, " \"");
		tmp = ft_strjoin(ft_strjoin(tmp, *cmd_tkn), "\" ");
		cmd_tkn++;
	}
	end[c_all] = tmp;
	return (end);
}

char	*ft_new_string(char **cmd_tkn)
{
	int		c_all;
	char	*tmp;

	c_all = 0;
	tmp = NULL;
	tmp = ft_strdup("");
	while (*cmd_tkn)
	{
		tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, *cmd_tkn);
		cmd_tkn++;
	}
	return (tmp);
}
