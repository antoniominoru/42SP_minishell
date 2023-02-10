/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:56:27 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/11 00:51:23 by jvictor-         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

# define ERROR 127
# define NO_ERROR 0

//EXECUTION FLAGS
# define F_INTERN 1
# define F_BUILTIN 0

extern int	g_current_status;

void	minishell(char	*cmd, t_list *lst_env, char **path);
t_list	*env_to_lst(char *envp[]);
void	print_list(t_list *lst);
void	define_signals(void);
void	sig_handler(int signal);
void	sig_handler_fork(int signal);
void	define_signals_fork(void);
void	free_all(t_list **lst_env, char *cmd, char **cmd_tkn);
void	free_part(t_list **lst_env, char **cmd, char **path);
void	free_tkn(char **cmd_tkn);
int		have_cmd(char *cmd);
void	ft_add_history(char *cmd);
void	status_error(char *msg, int error_status);

void	builtin_exit(t_list **lst_env, char *cmd, char **cmd_tkn);
void	exit_m_sh(t_list **lst_env, char *cmd, char **cmd_tkn, int arg_exit);
void	builtin_env(t_list *lst);
void	builtin_export(char *cmd, t_list **envp, int flag);
int		builtin_unset(char *cmd, t_list **envp, int flag);
void	builtin_all(char *cmd, t_list **envp, char **cmd_tkn);
void	builtin_pwd(void);
void	builtin_cd(char *cmd, t_list **envp);
void	builtin_echo(char **cmd_tkn);

char	*take_value_of_env(char *cmd, t_list **envp);
char	**tokenizer(char *cmd, char **cmd_tkn, t_list **envp);
int		count_words(char const *s, char c);
int		change_value_of_env(char *cmd, char *val, t_list **envp, int flag);
void	builtin_other(char **cmd, t_list **envp);
int		ft_ispipe(char *cmd);
void	builtin_pipe_to_all(char *cmd, t_list **envp);

#endif