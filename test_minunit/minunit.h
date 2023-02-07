/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:18:23 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/08 00:25:38 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINUNIT_H
# define MINUNIT_H

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../include/minishell.h"

# define ERROR 1
# define NO_ERROR 0

extern int	g_current_status;

char	*test_builtin_export(void);
char	*test_builtin_unset_initial(void);
char	*test_builtin_unset_between(void);
char	*test_builtin_unset_finish(void);
char	*test_builtin_env(void);
char	*test_builtin_pwd(void);
char	*test_builtin_echo(void);
char	*test_builtin_cd(void);
char	*test_take_value_of_env(void);
char	*test_change_value_of_env(void);
char	*test_tokenizer(void);
char	*test_builtin_other(void);
char	*test_builtin_cd_ft_ispipe(void);


/* file: minunit.h */
 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
 #define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)
 extern int tests_run;

#endif
 