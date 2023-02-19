/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all_complement.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:09:31 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/20 00:35:48 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_token(char **cmd_tkn)
{
	int		c_all;
	char	*tmp;
	char	**end;
	int		test;

	c_all = 0;
	tmp = NULL;
	end = NULL;
	test = cont_pipe_token(cmd_tkn);
	end = malloc(( test + 2) * sizeof(char *));
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
			tmp = "";
		else
			tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, *cmd_tkn);
		cmd_tkn++;
	}
	end[c_all] = tmp;
	end[c_all + 1] = NULL;
	return (end);
}

char	*ft_new_string(char **cmd_tkn)
{
	int		c_all;
	char	*new_str;
	char	*tmp;
	char	*tmp2;

	c_all = 0;
	new_str = NULL;
	new_str = ft_strdup("");
	while (*cmd_tkn)
	{
		tmp2 = new_str;
		tmp = ft_strjoin(new_str, " ");
		// free(new_str);
		new_str = ft_strjoin(tmp, *cmd_tkn);
		cmd_tkn++;
		free(tmp);
		free(tmp2);
	}
	return (new_str);
}
