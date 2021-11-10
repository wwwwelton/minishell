/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:37:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/10 11:58:30 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef DEBUG
#  define DEBUG 1
# endif
# define SQUOTES 27
# define DQUOTES 22
# define NEWPAT "___0x4242___"

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

char		**g_environ;

typedef struct s_flags
{
	char				*file_out;
	char				*file_in;
	int					builtins;
	int					system_cmd;
}	t_flags;

typedef struct s_builtin
{
	char				*name;
	void				(*f)(char **);
	struct s_builtin	*next;
}	t_builtin;

typedef struct s_patterns
{
	char	*backup[50];
	char	*holder[50];
	int		i;
}	t_patterns;

typedef struct s_data
{
	char				**presplit;
	char				***cmd;
	char				**path;
	char				**accesspath;
	t_patterns			*patterns;
	t_flags				**flags;
	t_builtin			*head;
}	t_data;

typedef struct s_cmd
{
	char				**cmd;
	char				*path;
	char				*accesspath;
	t_patterns			*patterns;
	t_flags				**flags;
	t_builtin			*head;
}	t_cmd;

void	init_builtins(t_builtin **head);
void	init_patterns(t_patterns **patterns);
void	init_data(t_data **data);

void	printfunctions(t_builtin *head);
void	minishell(t_data *data);
void	parser(t_data *data);
char	*prompt_user(void);
void	translate(t_data *data);
void	debug(t_data *data);

// void	translate(t_data)

void	alt_echo(char *str);
void	alt_cd(char *str);
void	alt_pwd(char *str);
void	alt_env(char *str);
void	alt_unset(char *str);
void	alt_exit(char *str);
void	alt_export(char *str);
void	alt_minishell(char *str);

#endif
