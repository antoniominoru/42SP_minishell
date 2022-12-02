/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:56:27 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/01 20:54:05 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// lib of 42 projects
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"

// lib of readline
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

int	ft_add_history(char *cmd);
t_list  env_to_lst(char *envp[]);

#endif