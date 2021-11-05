/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:37:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/05 03:23:09 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
#include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

char		**g_environ;
typedef struct s_builtin
{
	char				*name;
	void				(*f)(char *);
	struct s_builtin	*next;
}	t_builtin;

void	init_builtins(t_builtin **head);
void	printfunctions(t_builtin *head);

void	minishell(void);

void	alt_echo(char *str);
void	alt_cd(char *str);
void	alt_pwd(char *str);
void	alt_env(char *str);
void	alt_unset(char *str);
void	alt_exit(char *str);
void	alt_export(char *str);

#endif
