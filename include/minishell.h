/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:56:27 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/06 22:35:52 by aminoru-         ###   ########.fr       */
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

int		ft_add_history(char *cmd);
t_list	*env_to_lst(char *envp[]);
void	print_list(t_list *lst);
int		builtin_all(char *cmd, t_list *envp);
int     builtin_exit(char *cmd);
int		builtin_env(t_list *lst);
int 	builtin_export(char *cmd, t_list *envp);
int 	builtin_unset(char *cmd, t_list *envp);

#endif