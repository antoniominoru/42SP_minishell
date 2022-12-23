/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:56:27 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/23 01:03:47 by aminoru-         ###   ########.fr       */
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
# include <signal.h>
# include <unistd.h>

t_list	*env_to_lst(char *envp[]);
void	print_list(t_list *lst);
void	define_signals(void);
void	sig_handler(int signal);
void	free_all(t_list **lst_env, char *cmd);
void	free_lst_env(t_list **lst_env);
void	ft_add_history(char *cmd);
int		builtin_exit(void);
int		builtin_env(t_list *lst);
int		builtin_export(char *cmd, t_list *envp);
int		builtin_unset(char *cmd, t_list **envp);
int		builtin_all(char *cmd, t_list **envp, int status);
int		builtin_pwd(void);
void	builtin_echo(char *cmd);
int		builtin_cd(char *cmd, t_list **envp);
char	*take_value_of_env(char *cmd, t_list **envp);
char	**tokenizer(char *cmd);

#endif